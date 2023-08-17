# mit-6.s081-lab-2020fall
The lab code of MIT 6.S081
## Environment setup
https://zhuanlan.zhihu.com/p/504164986  
**Ubuntu**
```shell
sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu  -y && 
sudo apt install gcc-riscv64-unknown-elf -y  && 
sudo apt-get install qemu-system-misc=1:4.2-3ubuntu6

git clone git://g.csail.mit.edu/xv6-labs-2020
cd xv6-labs-2020
git checkout util

# when making grade, python2 is needed，but python3 installed. Make a ln
sudo ln /usr/bin/python3 /usr/bin/python
```

```shell
cd xv6-labs-2020/
make qemu
```


### lab1 : [Unix utilities](https://pdos.csail.mit.edu/6.S081/2020/labs/util.html)   

### lab2 : [System calls](https://pdos.csail.mit.edu/6.828/2020/labs/syscall.html)   

### lab3 : [Page tables](https://pdos.csail.mit.edu/6.828/2020/labs/pgtbl.html)    

### lab4 : [Traps](https://pdos.csail.mit.edu/6.828/2020/labs/traps.html)

### lab5 : [Lazy page allocation](https://pdos.csail.mit.edu/6.828/2020/labs/lazy.html)

### Lab6 : [Copy-on-Write](https://pdos.csail.mit.edu/6.828/2020/labs/cow.html) 

### lab7 : [Multithreading](https://pdos.csail.mit.edu/6.828/2020/labs/thread.html)     

### Lab8 : [Locking](https://pdos.csail.mit.edu/6.S081/2020/labs/lock.html)


### Lab9 : [File system](https://pdos.csail.mit.edu/6.S081/2020/labs/fs.html)


### Lab10 : [Mmap](https://pdos.csail.mit.edu/6.S081/2020/labs/mmap.html)


### Reference
[6.S081 Home page](https://pdos.csail.mit.edu/6.S081/2020/)
[6.1810 Home page](https://pdos.csail.mit.edu/6.828/2022)

[Chinese](https://mit-public-courses-cn-translatio.gitbook.io/mit6-s081/)

[![Readme Card](https://github-readme-stats.vercel.app/api/pin/?username=huihongxiao&repo=MIT6.S081)](https://github.com/huihongxiao/MIT6.S081)

[![Readme Card](https://github-readme-stats.vercel.app/api/pin/?username=duguosheng&repo=6.S081-All-in-one)](https://github.com/duguosheng/6.S081-All-in-one)

[![Readme Card](https://github-readme-stats.vercel.app/api/pin/?username=PKUFlyingPig&repo=MIT6.S081-2020fall)](https://github.com/PKUFlyingPig/MIT6.S081-2020fall)
