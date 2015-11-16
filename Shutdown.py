# -*- coding: utf-8-*-
import random
import re
import sys
import time
import signal
import os

WORDS = ["SHUTDOWN"]

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

    i=0
    n=["5","4","3","2","1"]
    mic.say("Jasper will shutdown after five second.")
    while i<5:
        print n[i]
        mic.say(n[i])
        i+=1
        time.sleep(0.3)
    mic.say("Bye Bye")
    os.kill(os.getpid(),signal.SIGKILL)


def isValid(text):
    """
        Returns True if the input is related to the meaning of life.

        Arguments:
        text -- user-input, typically transcribed speech
    """
    return bool(re.search(r'\bshutdown\b', text, re.IGNORECASE))
