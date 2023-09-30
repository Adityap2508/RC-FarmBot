# RC-FarmBot

Idea :

Agriculture is the backbone of any economy. It plays a pivotal role in the functioning of any developing or developed nations. We created a project that primarily helps the agricultural sector. It allows farmers to take informed decisions around the amount of water and fertilizers to be added by measuring the temperature and moisture level of the soil. 

Problem Statement:

Temperature and adequate water level are most essential factors for growing crops. Soil temperature influences plant growth as warmth promotes crop development through increased water and nutrient uptake from the soil. Soil moisture is also the critical parameter in agriculture. If there is a shortage or abundance of water, crops may not able to survive. 
Farmers face challenges in effectively monitoring the soil conditions including soil moisture and temperature. Traditional methods often involve manual labor and are time-consuming, leading to suboptimal resource allocation and potentially reduced crop yields. Therefore, there is a need for an automated solution that can traverse the farm, collect accurate and real-time data on soil moisture and temperature and provide actionable insights for farmers so they can take accurate decision on watering, proper timing for sowing the seed etc. RC FarmBot is a remote-controlled car which navigates the farm and measures soil moisture and temperature for farmers to monitor their crops and make informed decisions.

SDG in focus:

The RC FarmBot can help achieve SDG 13, 15 by improving agricultural productivity and efficiency. By monitoring soil moisture and providing real-time data, farmers can optimize irrigation practices, reduce water waste, and enhance crop yields, thus contributing to food security and sustainable farming.

Constraints:

Environmental Factors: The RC car will be exposed to various environmental conditions, including dust, moisture, and temperature fluctuations. The sensors should be rugged and weatherproof to withstand these conditions and provide accurate readings consistently.

Integration and Compatibility: Ensuring compatibility and proper integration between the sensors, microcontroller, and communication module is crucial. It involves selecting components that can communicate with each other effectively and developing appropriate software or firmware to process and transmit the collected data.

Final Solution:	

We brainstormed multiple ideas onto a google sheet. With some research we decided to build RC FarmBot using Arduino Uno Microcontroller connected to  Soil Moisture and DHT Sensor and a WiFi Module.  

After planning, we ordered all necessary material including sensors etc. We made a prototype with cardboard which helped determine the size that the body needed to be in order to stack up the sensors within it. We also 3D printed the insertion and extraction tool to measure the soil.

All the sensors were tested individually multiple times and worked well after being tried. We fitted the Arduino Uno and required Sensors along with the Insertion Extraction Tool in the Remote Controlled Car. Fitting the varied electronics in the car was not an easy operation, the chassis of the car needed to be tweaked and wiring had to be slightly changed in order to accomplish a finished product. 

Once the RC Car i.e. FarmBot got mechanically constructed, we programmed in Arduino IDE to capture soil moisture and soil temperature levels which are then sent to email via WiFi connectivity. We used IOT for sending the mail using Adafruit. 

With several attempts of trial and error, we could fine tune the program so that sensors could capture the required data as expected.




