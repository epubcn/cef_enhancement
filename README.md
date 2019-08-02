这里放一些针对CEF(Chromium Embedded Framework)的修改，以及编译命令等。C++版本。

### getDisplayMedia
官方版本不支持js调用getDisplayMedia()进行屏幕+窗口共享，这个目录下包含了针对特定一些CEF版本的代码补丁，目录结构按照src为根目录排列。直接对应版本替换即可。代码补丁基于Chromium源码修改，主要是增加了Cef namespace，以及一些适配性改动（例如去除Tab页共享）

### Building
关于编译CEF的说明、注意事项、环境变量设置、编译参数说明等
