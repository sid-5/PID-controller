## PID-Controller For Self Balancing Ball On Beam
In this project we are trying to balance a ball on a V-beam by taking input from user where to balance it(eg. set point=12cm i.e 12cm away from the edge having the IR sensor).
We are using the PID(proportional-integral-derivative) algorithm by taking input for the IR sensor present at one edge of the V-beam and using the servo motor attached to the leg of the V-beam to change the orientation of the beam that in turn moves the ball along the beam. We designed a custom PCB to use the ATMEGA328P MCU.
### ![PID-controller-Block-diagram](https://user-images.githubusercontent.com/70048742/226980648-a0883ce9-688e-49a7-91c6-7d9c9c84d3ae.png)

----

## Project Images
![Semantic description of image](/Images/final_image1.jpg)
![Semantic description of image](/Images/final_image2.jpg)

----

## Project Video
![Semantic description of image](/Video/PID_BALANCE_VID_Trim.gif "Hinge")

<!-- <figure class="video_container">
  <video controls="true" allowfullscreen="true">
    <source src="/Video/PID_BALANCE_VID.mp4" type="video/mp4">
    <source src="/Video/video_20220518_170210.mov" type="video/mov"> 
  </video>
</figure> -->
