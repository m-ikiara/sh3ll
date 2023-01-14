# simple_shell

## General Idea

```sh
	vagrant@ubuntu-focal:~$ sh
	$ pwd
	/home/vagrant
	$ ls
	simple_shell
	$ cd simple_shell
	$ pwd
	/home/vagrant/simple_shell
	$ cd ..
	$ pwd
	/home/vagrant
	$ /bin/ls -l /tmp
	total 20
	drwx------ 2 vagrant vagrant 4096 Jan 14 10:16 nvim9GyfPm
	drwx------ 3 root    root    4096 Jan 14 07:52 snap-private-tmp
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-ModemManager.service-jThi6h
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-systemd-logind.service-Has8nj
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-systemd-resolved.service-kguori
	$ ls -l /tmp
	drwx------ 2 vagrant vagrant 4096 Jan 14 10:16 nvim9GyfPm
	drwx------ 3 root    root    4096 Jan 14 07:52 snap-private-tmp
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-ModemManager.service-jThi6h
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-systemd-logind.service-Has8nj
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-systemd-resolved.service-kguori
	$ ^C
	$ ^C
	$ exit
	vagrant@ubuntu-focal:~$ echo "/bin/ls -l /tmp" | ./sh
	drwx------ 2 vagrant vagrant 4096 Jan 14 10:16 nvim9GyfPm
	drwx------ 3 root    root    4096 Jan 14 07:52 snap-private-tmp
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-ModemManager.service-jThi6h
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-systemd-logind.service-Has8nj
	drwx------ 3 root    root    4096 Jan 14 07:52 systemd-private-34141bcff09c4857b42932abb55eb61d-systemd-resolved.service-kguori
	vagrant@ubuntu-focal:~$
```

## Definition of Terms

_Shell_

> It is a computer program that exposes an operating system's services to a human user or other programs.([Wikipedia](https://en.wikipedia.org/wiki/Shell_(computing))) It is the means of the user to communicate with the OS kernel.

## What this, actually, is for

This is the repository for the Shell implementation, in C, project by @alx\_africa. Amazing, right? :grinning:

## Sidebar

This will be fun! :tada:
