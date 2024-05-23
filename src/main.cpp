# include "mbed.h"
# include "firstpenguin.hpp"
constexpr uint32_t can_id = 35;

BufferedSerial pc(USBTX, USBRX, 9600); // パソコンとのシリアル通信
// プルアップ抵抗を持つデジタル入力を作成します。
CAN can(PA_11, PA_12, (int)1e6);
CANMessage msg;
DigitalIn button(BUTTON1, PullUp);
FirstPenguin penguin{can_id, can};

int main () {
  while(1) {
    button.read(); // ボタンの状態を読み取ります。
    // ボタンが押されたかどうかを確認します。
    if(button == 0) {
      // ボタンが押された時の処理
      penguin.pwm[0] = 10000;
      penguin.pwm[1] = 10000;
      penguin.pwm[2] = 10000;
      penguin.pwm[3] = 10000;
      printf("ボタンが押されました。\n");
    }
  }
}