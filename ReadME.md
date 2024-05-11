# ESP8266 項目 README

這是一個基於 ESP8266 微控制器的項目，用於示範如何使用 Arduino 開發環境進行開發。

## 簡介

此項目使用 Arduino 開發環境和 ESP8266 微控制器。它包括兩個主要部分：

- `user.cpp` 和 `user.h`：包含用於測試的用戶定義函數。
- `util.cpp` 和 `util.h`：包含用於網絡通信的輔助功能。

## 項目結構

- `main.ino`: 主程序入口，包含 `setup()` 和 `loop()` 函數，初始化 Wi-Fi 連接並調用定義的任務。
- `user.cpp` 和 `user.h`: 用戶定義的函數，包括測試和心跳功能。
- `util.cpp` 和 `util.h`: 包含用於 Wi-Fi 初始化和網絡請求的輔助函數，以及定義的 `Job` 類。

## 使用方法

1. 將代碼燒錄到 ESP8266 微控制器中。
2. 連接 ESP8266 到 Wi-Fi 網絡。
3. 監控串口，查看測試和心跳功能的輸出以及網絡請求的結果。

## 依賴項

- ArduinoJson: 用於解析 JSON 數據。
- ESP8266WiFi: ESP8266 的 Wi-Fi 庫。
- ESP8266HTTPClient: 用於發送 HTTP 請求。

## 注意事項

- 請確保在使用前修改 Wi-Fi 連接函數中的 SSID 和密碼。
- 此代碼僅作示範和測試用途，實際應用中請根據需要進行修改和擴展。

## 貢獻者

- [OomaybeoO](https://github.com/fainstar)

## 授權

此項目根據 MIT 授權條款發布。詳細信息請參見 [LICENSE](LICENSE) 文件。
