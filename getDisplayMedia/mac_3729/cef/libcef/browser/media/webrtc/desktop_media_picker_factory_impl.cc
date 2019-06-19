// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/media/webrtc/desktop_media_picker_factory_impl.h"

#include "base/no_destructor.h"
#include "build/build_config.h"
#include "libcef/browser/media/webrtc/native_desktop_media_list.h"
#include "content/public/browser/desktop_capture.h"

namespace Cef{
DesktopMediaPickerFactoryImpl::DesktopMediaPickerFactoryImpl() = default;

DesktopMediaPickerFactoryImpl::~DesktopMediaPickerFactoryImpl() = default;

// static
DesktopMediaPickerFactoryImpl* DesktopMediaPickerFactoryImpl::GetInstance() {
  static base::NoDestructor<DesktopMediaPickerFactoryImpl> impl;
  return impl.get();
}

std::unique_ptr<DesktopMediaPicker>
DesktopMediaPickerFactoryImpl::CreatePicker() {
// DesktopMediaPicker is implemented only for Windows, OSX and Aura Linux
// builds.
#if defined(TOOLKIT_VIEWS) || defined(OS_MACOSX)
  return DesktopMediaPicker::Create();
#else
  return nullptr;
#endif
}

std::vector<std::unique_ptr<DesktopMediaList>>
DesktopMediaPickerFactoryImpl::CreateMediaList(
    const std::vector<content::DesktopMediaID::Type>& types) {
  // Keep same order as the input |sources| and avoid duplicates.
  std::vector<std::unique_ptr<DesktopMediaList>> source_lists;
  bool have_screen_list = false;
  bool have_window_list = false;
  for (auto source_type : types) {
    switch (source_type) {
      case content::DesktopMediaID::TYPE_NONE:
        break;
      case content::DesktopMediaID::TYPE_SCREEN: {
        if (have_screen_list)
          continue;
        std::unique_ptr<DesktopMediaList> screen_list;
        screen_list = std::make_unique<NativeDesktopMediaList>(
            content::DesktopMediaID::TYPE_SCREEN,
            content::desktop_capture::CreateScreenCapturer());
        have_screen_list = true;
        source_lists.push_back(std::move(screen_list));
        break;
      }
      case content::DesktopMediaID::TYPE_WINDOW: {
        if (have_window_list)
          continue;
        std::unique_ptr<DesktopMediaList> window_list;
        window_list = std::make_unique<NativeDesktopMediaList>(
            content::DesktopMediaID::TYPE_WINDOW,
            content::desktop_capture::CreateWindowCapturer());
        have_window_list = true;
        source_lists.push_back(std::move(window_list));
        break;
      }
      // not support
      case content::DesktopMediaID::TYPE_WEB_CONTENTS: {
        break;
      }
    }
  }
  return source_lists;
}
}//namespace Cef
