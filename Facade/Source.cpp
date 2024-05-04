#include <iostream>
#include <cstdlib>
using namespace std;

class VideoCard {
public:
    void PowerOn() {cout << "(Video Card) Powered On\nVideo Card: Power On Successful" << endl;}
    void Start() {cout << "(Video Card) Started" << endl;}
    void DisplayInfo() {cout << "(Video Card) Displaying Information" << endl;}
    void PowerOff() {cout << "(Video Card) Powered Off" << endl;}
};

class RAM {
public:
    void PowerOn() {cout << "(RAM) Powered On\nRAM: Power On Successful" << endl;}
    void Start() {cout << "(RAM) Started" << endl;}
    void AnalyzeMemory() {cout << "(RAM) Analyzing Memory" << endl;}
    void ClearMemory() {cout << "(RAM) Clearing Memory" << endl;}
    void PowerOff() {cout << "(RAM) Powered Off\n";}
};

class HardDisk {
public:
    void PowerOn() {cout << "(HDD) Powered On\n(HDD) Power On Successful\n";}
    void Start() {cout << "(HDD) Started\n";}
    void CheckBootSector() {cout << "(HDD) Checking Boot Sector\n";}
    void PowerOff() {cout << "(HDD) Powered Off\n";}
};

class OpticalDrive {
public:
    void PowerOn() {cout << "(Optical Drive) Powered On\nOptical Drive: Power On Successful\n";}
    void Start() {cout << "(Optical Drive) Started\n";}
    void CheckDisc() {cout << "(Optical Drive) Checking Disc\n";}
    void PowerOff() {cout << "(Optical Drive) Powered Off\n";}
};

class PowerSupply {
public:
    void PowerOn() {cout << "(Power Supply) Powered On\nPower Supply: Power On Successful\n";}
    void PowerOff() {cout << "(Power Supply) Powered Off\n";}
};

class Sensors {
public:
    void CheckVoltage() {cout << "(Sensors) Checking Voltage\n";}
    void CheckTemperature(string device) {cout << "(Sensors) Checking Temperature in " << device << "\n";}
};

class ComputerFacade {
    VideoCard gpu;
    RAM ram;
    HardDisk hdd;
    OpticalDrive rom;
    PowerSupply power;
    Sensors sens;
public:
    void BeginWork() { cout << "Starting Computer...\n";
        power.PowerOn();
        sens.CheckVoltage();
        sens.CheckTemperature("Power Supply");
        sens.CheckTemperature("Video Card");
        gpu.PowerOn();
        gpu.Start();
        gpu.DisplayInfo();
        sens.CheckTemperature("RAM");
        ram.PowerOn();
        ram.Start();
        ram.AnalyzeMemory();
        gpu.DisplayInfo();
        rom.PowerOn();
        rom.Start();
        rom.CheckDisc();
        gpu.DisplayInfo();
        hdd.PowerOn();
        hdd.Start();
        hdd.CheckBootSector();
        gpu.DisplayInfo();
        sens.CheckTemperature("all systems");
    }

    void EndWork() { cout << "\nShutting Down Computer.\n";
        hdd.PowerOff();
        rom.PowerOff();
        gpu.PowerOff();
        ram.ClearMemory();
        ram.PowerOff();
        power.PowerOff();
        sens.CheckVoltage();
    }
};

int main() {
    srand((time(NULL)));
    ComputerFacade pc;
    pc.BeginWork();
    pc.EndWork();
    system("pause");
    return 0;
}