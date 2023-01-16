# Vast Power 固件

目前固件处于测试阶段，并没有完成所有功能的开发与调试。

## 固件下载

* ESP32固件
  * [查看](ESPHome/)
* SU-03T固件
  * 固件 [su_03t_release_update_20221219001_1.1.9](Firmware/SU-03T/su_03t_release_update_20221219001_1.1.9.bin)
  * 烧录软件 [Hummingbird-M-Update-Tool](https://docs.aimachip.com/zh_CN/latest/_static/document/SU-03T/Hummingbird-M-Update-Tool.zip)

## 固件烧录

### ESP32固件烧录方法
初次使用，编译完固件后，下载bin文件。

切断设备供电，短接主板上面2PIN脚，连上USB线，使用ESPHome-Flasher烧录。

### SU-03T固件烧录方法
烧录完ESP32固件后设备连上网络，在HomeAssistant里配置-设备与服务-添加集成-ESPHOME。添加完成后，在集成中找到并进入设备。

![su1](images/su1.jpg)

![su2](images/su2.jpg)

关闭语音模块电源，打开语音模块烧录

![su3](images/su3.jpg)

连上USB线，打开烧录软件，点烧录后出现黄色的COM端口

![su4](images/su4.jpg)

回到HomeAssistant，打开语音模块电源，此时烧录软件开始工作，等待进度完成即可

## ESP32与SU-03T互动

ESP32与SU-03T通过UART接口互动，具体消息内容请参考下方介绍。

| SU-03T发送给ESP32消息内容及意义  | |
|  消息内容  | 代表含义  |
| ----  | ----  |
| 10 11 | 开照明灯 |
| 10 10 | 关照明灯 |
| 10 21 | 开氛围灯 |
| 10 20 | 关氛围灯 |
| 20 11 | 调亮灯光 |
| 20 10 | 调暗灯光 |
| 30 11 | 打开电源 |
| 30 10 | 关闭电源 |
| 40 01 | 暂停打印 |
| 40 10 | 恢复打印 |
| 40 11 | 取消打印 |
| 50 00 | 打印进度 |

| ESP32发送给SU-03T的消息内容及意义  | |
|  消息内容  | 代表含义  |
| ----  | ----  |
| AA 55 01 00 00 00 00 55 AA  | 关闭电源判断，返回打印中 |
| AA 55 02 01 00 00 00 55 AA  | 关闭电源判断，返回未打印 |
| AA 55 03 01 00 00 00 55 AA  | 开始OTA |
| AA 55 04 01 00 00 00 55 AA  | 结束OTA |
| AA 55 05 00 01 02 55 AA  | 打印进度返回，00对应进度百分比数字，01对应剩余小时数字，02对应剩余分钟数字 |


## FAQs

待补充
