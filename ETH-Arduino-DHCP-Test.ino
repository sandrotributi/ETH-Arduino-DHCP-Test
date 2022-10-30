#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // attendere la connessione della porta seriale. Necessario solo per la porta USB nativa.
  }
  Ethernet.init(10);
  // inizializazione Ethernet
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Impossibile configurare Ethernet tramite DHCP");
    // verifica la presenza di hardware Ethernet
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("La shield Ethernet non è stata trovata. Spiacenti, impossibile eseguire senza hardware. :(");
    } else if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Cavo Ethernet non connesso.");
    }
    // non ha senso andare avanti, quindi non fare nulla per sempre:
    while (true) {
      delay(1);
    }
  }

  // visualizza indirizzo MAC
  byte macBuffer[6];
  Ethernet.MACAddress(macBuffer); 
  Serial.print("MAC: ");
  for (byte octet = 0; octet < 6; octet++) {
    Serial.print(macBuffer[octet], HEX);
    if (octet < 5) {
      Serial.print(':');
    }
  }
  Serial.println();
  // visualizza indirizzo IP
  Serial.print("IP:  ");
  Serial.println(Ethernet.localIP());
  // visualizza subnet mask 
  Serial.print("SM:  ");
  Serial.println(Ethernet.subnetMask());
  // visualizza IP gateway 
  Serial.print("GW:  ");
  Serial.println(Ethernet.gatewayIP());
  // visualizza IP DNS server
  Serial.print("DNS: ");
  Serial.println(Ethernet.dnsServerIP());
}

void loop() {

}
