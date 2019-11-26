推荐按照正式分支版本来编译，CEF官网编译教程：https://bitbucket.org/chromiumembedded/cef/wiki/BranchesAndBuilding

## 命令行/Terminal设置上网代理 [为什么要设置代理？你懂的]
set http_proxy=http://127.0.0.1:1080  
set https_proxy=http://127.0.0.1:1080  
端口号按需修改  

## 编译环境变量
### Windows
set CEF_USE_GN=1  
set GN_DEFINES=is_official_build=true proprietary_codecs=true ffmpeg_branding=Chrome  
set GYP_DEFINES=buildtype=Official  
set GYP_MSVS_VERSION=2017  
set CEF_ARCHIVE_FORMAT=tar.bz2  
set GN_ARGUMENTS=--ide=vs2017 --sln=cef --filters=//cef/*  
### macOS
export CEF_USE_GN=1  
export GN_DEFINES="is_official_build=true proprietary_codecs=true ffmpeg_branding=Chrome"  
export GYP_DEFINES=buildtype=Official  
export CEF_ARCHIVE_FORMAT=tar.bz2  

## 编译参数
--download-dir 源码下载目录  
--depot-tools-dir 工具包目录  
--branch=分支号，如3538  
--no-build 下载完不自动开始编译  
--no-update 确定源码下载完毕仅重新编译时使用  
--force-build 强制编译（发现在有成功编译的时候再编译不会执行，可以加上这个）  
--no-debug-build 只编译release版本  
--no-release-build 只编译debug版本  
--x64-build 编译x64版本  
--force-update 强制更新  
--force-config  
--force-clean-deps  
--minimal-distrib 产生不包含cefclient/cefsimple等测试工程的包  
--client-distrib 产生cefclient程序包（编译好的可以直接运行）  
更多参数可以参考 https://bitbucket.org/chromiumembedded/cef/raw/master/tools/automate/automate-git.py

## 编译命令示例
python automate-git.py --download-dir=D:\google\cef\source --branch=3729 --no-update --force-clean --force-build  


