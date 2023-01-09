# Vast Power 固件

目前固件处于测试阶段，并没有完成所有功能的开发与调试。

## 固件下载

* ESP32固件
  * [查看](Firmware/ESPHome/)
* SU-03T固件
  * 固件 [su_03t_release_update_20221219001_1.1.9](Firmware/SU-03T/su_03t_release_update_20221219001_1.1.9.bin)
  * 烧录软件 [Hummingbird-M-Update-Tool](https://docs.aimachip.com/zh_CN/latest/_static/document/SU-03T/Hummingbird-M-Update-Tool.zip)

## ESP32与SU-03T互动

ESP32与SU-03T通过UART接口互动，具体消息内容请参考下方介绍。

* SU-03T发送给ESP32消息内容及意义

- 10 11  开照明灯
- 10 10  关照明灯
- 10 21  开氛围灯
- 10 20  关氛围灯
- 20 11  调亮灯光
- 20 10  调暗灯光
- 30 11  打开电源
- 30 10  关闭电源
- 40 01  暂停打印
- 40 10  恢复打印
- 40 11  取消打印
- 50 00  打印进度

* ESP32发送给SU-03T的消息内容及意义

- AA 55 01 00 00 00 00 55 AA   关闭电源判断，返回打印中
- AA 55 02 01 00 00 00 55 AA   关闭电源判断，返回未打印
- AA 55 03 01 00 00 00 55 AA   开始OTA
- AA 55 04 01 00 00 00 55 AA   结束OTA
- AA 55 05 00 01 02 55 AA   打印进度返回，00对应进度百分比数字，01对应剩余小时数字，02对应剩余分钟数字


## FAQs

待补充