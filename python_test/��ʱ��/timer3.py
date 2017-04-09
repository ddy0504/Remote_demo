# -*- coding: utf-8 -*-


from abc import ABCMeta, abstractmethod
import time  
import threading  

class BaseTimer(threading.Thread):
    """
    基础定时器抽象类，可以随意继承本类并且实现exec抽象方法即可定时产生任务
    """
    __metaclass__ = ABCMeta
    def __init__(self,howtime=1.0,enduring=True):
        """
        howtime 每次定时的时间
        enduring 是否是一个持久性的任务，用这个可以控制开关
        """

        self.enduring = enduring
        self.howtime = howtime
        threading.Thread.__init__(self)
    
    def run(self):
        time.sleep(self.howtime)  #至少执行一次 任务
        self.exec()
        while self.enduring:    #是否持久，或者是否进行运行
            time.sleep(self.howtime)
            self.exec()    #每次开始执行任务

    @abstractmethod
    def exec(self):    
        """抽象方法，子类实现"""
        pass

    def destroy(self):
        """销毁自身"""
        self.enduring = False
        del self

    def stop(self):
        self.enduring = False

    def restart(self):
        self.enduring = True
        
    def get_status(self):
        return self.enduring



class TimerMask(BaseTimer):
    """定时任务类，不同的业务逻辑"""
    def __init__(self,howtime=1.0,enduring=True):
        BaseTimer.__init__(self,howtime,enduring)
        self.ws=0

    def exec(self):
        print("HelloWorld!")
        self.ws = self.ws + 1  #这里是过0.8秒输出一次
        if self.ws >5:
            self.destroy()

if __name__ == "__main__":
    Q_w = 0
    w = TimerMask(howtime=0.8)
    print("-")
    w.start() 
    #这里线程输出这些，做其他事情的
    while True:
        time.sleep(0.4) #0.4秒
        print("- ",Q_w," - WMask:",w)  
        Q_w += 1
        pass
