#!/usr/bin/env python
import subprocess
subprocess.getstatusoutput("sudo usermod -a -G dialout $USER")
subprocess.getstatusoutput("sudo chmod a+rw /dev/ttyUSB1")
test = subprocess.getstatusoutput("rubiks-cube-tracker.py --webcam 0")
print(test)

