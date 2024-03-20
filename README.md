# Mirror
Mirror 125k/13.56mHZ RFID读写卡器软件代码，配套硬件: https://u.lceda.cn/account/user/projects/index/detail?project=671ac746ce1a418f8a3fe71eb952467f


<br/>

# 依赖：esp-idf
ESP32的项目依赖于乐鑫官方提供的基础环境，鉴于C语言没有强大的依赖管理功能，且git submodule功能也很难用。 本项目采用了最简单原始的方式：
1. git clone https://github.com/espressif/esp-idf.git 
2. cd esp-idf
3. git checkout v5.2-rc1
4. git submodule update
5. rm -rf .git 
6. cd ..


>基于
https://github.com/espressif/esp-idf.git <br/>
commit 11eaf41b37267ad7709c0899c284e3683d2f0b5e (HEAD, tag: v5.2-rc1, tag: v5.2)


# build
source esp-idf/export.sh
cd mirror_project && idf.py build