# ESP32-S3 8 通道音频采集直传 MinIO

## 项目简介

本工程是运行在 **ESP32-S3** 上的音频采集与上传固件，基于 **ESP-IDF v5.x**。ESP32-S3 作为 SPI 主机，从 STM32 SPI 从机 DMA 接收 8 通道 24bit PCM 音频数据，每 480 帧为一个 SPI 块（10ms），每 500 个块组成一个 5 秒音频段。

音频段存放在 PSRAM 双缓冲中。上传任务将 24bit 交错 PCM 实时转换为单声道 WAV，并打包为 ZIP（内部为 `CH1.wav` ~ `CH8.wav`），然后通过临时 STS 凭证直传 MinIO / S3 兼容对象存储。

## 硬件清单

| 部件          | 建议规格                             | 说明                                                       |
| :------------ | :----------------------------------- | :--------------------------------------------------------- |
| ESP32-S3 芯片 | ESP32-S3 模组，**16MB PSRAM**        | ESP32-S3-WROOM-1U-N16R16V                                  |
| STM32 主控    | 带 SPI Slave + DMA，3.3V 电平        | STM32F405RGT6                                              |
| 音频源        | 8 通道数字麦克风 / ADC，48kHz，24bit | 输出交错 PCM24 LE，ZTS6672                                 |
| RGB 状态灯    | 共阴，3 路 GPIO                      | 红 GPIO7，绿 GPIO6，蓝 GPIO5，默认高电平点亮，MHP5050RGBDT |
| WiFi 路由器   | 2.4GHz                               | ESP32-S3 仅支持 2.4GHz                                     |
| MinIO / S3    | 对象存储服务                         | 需支持 S3 兼容 API、Multipart、临时凭证                    |
| 凭证服务      | HTTP 接口                            | 默认                                                       |
| 电源          | 5V / 3.3V，电流充足                  | PSRAM、WiFi、SPI 同时工作时注意供电                        |

### 默认引脚连接

| ESP32-S3 | 方向 | STM32        | 说明                         |
| :------- | :--- | :----------- | :--------------------------- |
| GPIO12   | 输出 | SPI SCK      | SPI 时钟，16MHz，Mode 0      |
| GPIO11   | 输出 | SPI MOSI     | ESP32 发送 dummy，STM32 接收 |
| GPIO13   | 输入 | SPI MISO     | STM32 DMA 输出音频块         |
| GPIO10   | 输出 | SPI CS / NSS | 手动片选，低有效             |
| GPIO9    | 输入 | PB9 / READY  | 高电平表示 STM32 已 arm DMA  |
| GND      | —    | GND          | 必须共地                     |

> 注意：ESP32-S3 是 SPI 主机，STM32 是 SPI 从机。STM32 的 MISO 接 ESP32 的 GPIO13，ESP32 的 GPIO11 发 dummy 数据。
