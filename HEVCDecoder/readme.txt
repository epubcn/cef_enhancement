注意事项：
1. 编译了支持HEVC解码的版本后，使用html5test.com测试还是提示不支持H.265，原因如下：
html5test.com 上检测浏览器是否支持HEVC是用 video.canPlayType() 检查以下两种codec是否支持而确定浏览器是否支持H.265的：
'video/mp4; codecs="hvc1.1.L0.0"'
'video/mp4; codecs="hev1.1.L0.0"'

但是在Chromium源码 media\base\video_codes.cc 中（Chromium 76 3809版本）：

// The specification for HEVC codec id strings can be found in ISO IEC 14496-15 dated 2012 or newer in the Annex E.3
bool ParseHEVCCodecId(...) { ... }

这两个值是不符合 ISO IEC 14496-15 规范的（参考Annex E.3），因此会显示不支持。实际上是可以播放HEVC文件的。

注：这两个codec在macOS Safari 13.0.4上是有效的，可以被识别的。

2. 修改只提供了branding=Chrome的32位windows版本。64位windows和macOS没有包含

3. play_hevc.html是测试使用video标签播放hevc编码的mp4的测试页面。测试用的hevc视频文件可以到 Elecard网站上找到一些（https://www.elecard.com/videos）

4. 存在的问题： 播放Elecard上提供的一个1280x720的HEVC MP4，画面中的物体（人、骑车）在运动中会规律性跳动一下，原因未知。播放一个3840x2160的HEVC MP4，画面整体会隔几秒卡顿一下。原因未知。测试机器：小米笔记本Pro 15.6 i7-8550 1.8G/16G