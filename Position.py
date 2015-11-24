# -*- coding: utf-8-*-
import random
import re
import subprocess,sys

WORDS = ["POSITION"]

def handle(text, mic, profile):
    """
        Responds to user-input, typically speech text, by relaying the
        meaning of life.

        Arguments:
        text -- user-input, typically transcribed speech
        mic -- used to interact with the user (for both input and output)
        profile -- contains information related to the user (e.g., phone
                   number)
    """

    mic.say("Scanning...")
    where=subprocess.Popen(["/home/pi/scan/test_scan.sh"],stdout=subprocess.PIPE)
    answer,err=where.communicate()
    print(answer)
    #answer=subprocess.call("/home/pi/test_scan.sh",shell=True)
    mic.say(answer)

def isValid(text):
    """
        Returns True if the input is related to the meaning of life.

        Arguments:
        text -- user-input, typically transcribed speech
    """
    return bool(re.search(r'\b(position)\b', text, re.IGNORECASE))
