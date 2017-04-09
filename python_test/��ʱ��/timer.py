import threading
 
class Person(object):
    def __init__(self):
        print ("init person")
         
    def speak(self):
        print ("speak")
         
def func():
    print ("hello") 
 
 
if __name__ == "__main__":
    p = Person()
    while True:
        timer = threading.Timer(5,func )
        print ("start")
        timer.start()
        timer.join()
        print ("after join")
