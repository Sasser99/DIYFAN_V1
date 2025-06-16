# DIY-Fan-V1

Files from the YouTube video:  
**"DIY Fan V1 – I Built This Modular Open Source Project"**

![Alt-Text](img/DIY_FAN_V1_Thumbnail.png)
https://www.youtube.com/watch?v=IbPePFFd2lk



## Project structure

- **ECAD/** – KiCad files  
- **CODE/** – Arduino code  
- **CAD/** – 3D models (STL, STEP)
- **BOM/** – Each assembly has its own BOM, organized in separate worksheets within a single .ods file (Assembly_Fan-Stage, Assembly_MainPCBA-Housing and Assembly_Tripod)



## License

This project is open source and licensed as follows:

- **ECAD:** CERN Open Hardware License v2.0  
- **CODE:** MIT License  
- **CAD:** Creative Commons Attribution 4.0 (CC BY 4.0)

➡️ For full license texts, see the [LICENSE](LICENSE) file.


## Story

I came up with the idea to develop a modular, battery-powered, open-source fan built around high-end gaming PC fans. Gaming PC fans have low power consumption and, in the best case, are very quiet. Both are qualities that are also useful when the goal is not to cool PC components, but people. Additionally, the goal was to create a visually appealing and functional design.

The result is a system with **three main assemblies**: 


### 1. Fan Stage

![Alt-Text](img/Assembly1.png)

- This assembly consists of three parts: a fan, the interface_V1 PCBA, and the shroud.
- I chose the **Noctua NF-A12x25 PWM chromax.black.swap**, which offers a solid balance between airflow and static pressure.
- Other fans can be used as long as they have similar characteristics (e.g., airflow and static pressure).
- The shroud **increases wind speed by around 80%**, allowing the fan to be placed further away while still being effective. More on this in the YouTube video! :)
- The interface_V1 PCBA is mounted on the side and connects to the fan, forwarding its signals.


### 2. Main Electronics Module

![Alt-Text](img/Assembly2.png)

- This module supplies approximately **10W** of power. With fans like the Noctua NF-A12x25, up to five fan stages can be powered simultaneously.
- A single **button** is used to cycle through PWM levels.
- Four **RGB LEDs**, visible through the plexiglass cover, indicate the active PWM level.

![Alt-Text](img/ArduinoNano.png)

- I chose the **Arduino Nano** because it's compact, easy to use via the Arduino IDE, and perfect for replicating the build—especially for those with Arduino experience.
- The Nano is mounted on a small **custom PCB** that also houses LEDs, DC-DC converters, and a few additional components. But don’t worry: the total component count remains very manageable.
- I also used a **15W power bank** instead of a custom battery to keep replication easy.


### 3. Tripod

![Alt-Text](img/Assembly3.png)

- The tripod is simple but functional. If the legs are cut cleanly, the fan stands level.
- It provides the necessary stability, and I think the wood finish enhances the overall aesthetic.


### Configurations

The overall goal was to create a modular system. The three assemblies can be combined in different configurations using mechanical connectors and standard **Ethernet cables**, which transmit both power and PWM signal. The following configurations are demonstrated in the YouTube video:

**Full Build (with 3/5 Fans)**

![Alt-Text](img/Build1.png)


**Desk Setup**

![Alt-Text](img/Build2.png)


**Split Mode (Left and Right → Stereo)**

![Alt-Text](img/Build3.png)





