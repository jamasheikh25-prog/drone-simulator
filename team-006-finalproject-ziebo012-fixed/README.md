Team:
team-006

Members:
ziebo012 - Ben Ziebol
sheik208 - Jama Sheikh

Overview:
This simulation model creates a map of the University of Minnesota campus. On this map shows the various buildings, roads, and entities.
The entities on the map consist of:
    -Human: a figure of a human that wanders around the map
    -Helicopter: a figure of a helicopter that flies above the map, it will notify every mile that it flies
    -Package: an entity that will be delivered to a designated location
    -Robot: when creating a delivery, a robot will be at the final destination to receive the package
    -Drone: the entity that will carry the package to the robot
    -Cooling Station: an entity that will be utililzed if the temperature of the package were to drop below its desired temperature
On the left side of the screen, there is a notification window that will display various bits of information including:
    -How far the helicopter has traveled
    -when a delivery is scheculed
    -when a delivery is completed
On the top right side of the screen, there is a panel with varoius controls of the simulation contained within the buttons are:
    -add human: adds another human
    -add drone: creates another drone that can transport packages
    -start delivery: pulls up addtional information and allows for the creation of a delivery
    -end simulation: ends the simulation

Instructions:
to compile and run the simulation model use:
    1st: make -j
    2nd: make run
    3rd: in a web browswer, enter "http://127.0.0.1:8081/" into the search bar and go to the page

Iteracting with the model:
    -clicking and dragging to rotate the camera view
    -holding right click to pan
    -mouse wheel to zoom in and out
    -clicking on the buttons will interact with them and do the desire functions

Requirements: 
The system shall keep track of the weather and temperature at all times

The system shall ensure that frozen food is delivered without melting

When a drone reaches a delivery location, the system shall confirm delivery

When a drone reaches a cooling location, the cooling station shall reduce the food’s temperature

When the weather changes, the system will recalculate how fast the food melts

When the reaches a warm enough temperature, the drone will update its route to include a cooling station

If the food reaches to warm of a temperature the observer will notify the recipient

If the weather is too warm to deliver frozen food then the observer will notify any recipients

While the drone is on route the drone will monitor the temperature of the food

While the food is at a cooling station the cooling station will cool the food

Where frozen food is included the drone shall adjust its route based on the temperature

While the food is an acceptable temperature, when the cooling station is unavaible, then the drone will continue to destination

When the weather temperature is freezing, where the food is supposed to be warm then the observer will notify the recipient of cold food



Interest:
In the real world, their may be some packages that are dependent on the content's temperature. We are able to simulate this and have it be weather dependent by these extensions being included. providing some insight into real world problems.

Design:
We added frozen food delivery by a combination of Decorators and extending the existing composite factory. Decorator allows us to add existing functionality while maintaining the original code (not editing it) we also extended the composite factory so that a cooling station factory could be made, allowing the handling of multiple new coolingstations

Weather we added as a singleton since we only want a single instance of the weather in the simulation.

Sprint retrospective: 
we ound that some of the things that worked well was
Communication: We felt that we had a strong sense of communication and keeping each othe updated about the stuff happening
Assistance: with that, we found that if one of us was ever stuck, we were easily able to reach out and get isight and 
assitance on the problem
Teamwork: we felt that we worked well together

Some things that we felt didn't work well
Schedules: There were some things that came up during the sprints taht made scheduling difficult

Things taht we felt that we could improve on
Timing: This builds off of scheduiling, we felt that while we delivered our production on time, if we could have managed our
time better we could have polished it up nicely


Youtube Video Presentation Link:
https://youtu.be/FMcVf6nKdI0

UML:
in git hub repo
![alt text](https://github.umn.edu/umn-csci-3081w-f24-sec010/team-006-finalproject/blob/ziebo012-fixed/UML-Final%20project%203081.pdf)