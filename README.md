# MSPM0G3507 电赛备赛项目

## 更新日志

### 2026-07-20 — I2C/OLED/Qfplib 优化 + 代码清理

#### 初始代码审查
- 已实现：电机PWM、QEI编码器、PID控制器、Mahony姿态解算、IMU660RB、
  7路灰度循迹、OLED菜单、按键、UART调参、标志系统、控制模式切换

#### I2C 驱动优化
- RX FIFO：IMU 读 14 寄存器从 28 次 I2C 事务降到 2 次
- TX FIFO：解除 8 字节限制，任意长度发送（FIFO 续填）

#### OLED 驱动优化
- 字符串批量显示：整行字模拼 buffer 一次发完
- Framebuffer 显存缓冲（oled_fb[8][128]），统一 OLED_Flush() 刷屏
- 静态页刷新不再多刷空白屏（新增 OLED_ClearBuffer）

#### Qfplib 浮点加速
- 集成 Qfplib-M0-tiny，atan2f/sqrtf 提速 ~17 倍
- 预编译开关 USE_QFP_MATH 1/0，跨平台移植

#### 代码清理
- 修 OLED_SetCursor 优先级缺括号
- 去重 string.h include，修拼写 Contorl/adders
- 移除 gcc/iar/ticlang 工程目录、README.html/md、Event.dot
- 新增 clean.bat 一键清理 Keil 编译缓存
