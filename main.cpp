#include "lora.h"
#include "mainwindow.h"
#include "transport_crc.h"
#include <QApplication>

transport_t lora_transport;

void lora_init(void) {
  lora_transport.onFrameDetected = lora_rx_frame_parse;
  lora_transport.send = lora_tx_frame;
  lora_transport.uplayer = &lora_transport;
  initTransportCRC(&lora_transport);
}

int main(int argc, char *argv[]) {
  /* 解决分辨率不同导致的文件压缩问题 */
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  lora_init();
  return a.exec();
}
