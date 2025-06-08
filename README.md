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

The result is a system with three main assemblys: 


**FAN Stage:**

![Alt-Text](img/Assembly1.png)

- The shroud increases the wind speed, which allows the device to be placed a bit further away while still being effective.
- In addition, the interface_V1 PCBA is installed on the side. The PC fan can be connected to this board, which then passes on the fan’s signals.
- Using the shroud increases the airflow speed by around **80%**! Feel free to check it out in the linked YouTube video :)


**Main Electronics Module:**

![Alt-Text](img/Assembly2.png)

- The electronics module provides approximately 10 W of power. When using fans such as the Noctua NF-A12x25 PWM chromax.black.swap, as I do, up to five fan stages can be operated simultaneously.

![Alt-Text](img/ArduinoNano.png)

- The Arduino Nano was just the right choice for this project – it’s compact and super easy to work with thanks to the Arduino IDE. Plus, using an Arduino makes it way easier for others to recreate the build, especially if you’ve played around with Arduinos before. The Nano sits on a small custom PCB to hook up a few extra parts – like some LEDs, a DC-DC converter, and one or two other small parts. But don’t worry: the number of components is totally manageable. So go ahead and give it a shot!


**Tripod:**

![Alt-Text](img/Assembly3.png)

The goal was to develop, among other things, a modular system. Therefore, the three assemblys can be assembled in various **configurations**. Here are the setups shown in the YouTube video:


**Full Build (with 3/5 Fans)**

![Alt-Text](img/Build1.png)


**Desk Setup**

![Alt-Text](img/Build2.png)


**Split Mode (Left and Right → Stereo)**

![Alt-Text](img/Build3.png)





