# SysTray-X

SysTray-X is a system tray extension for Thunderbird 68+. The add-on uses the WebExtension API's to control an external system dependent system tray application.  

The add-on and system tray application can do:

- custom new mail icon
- display number of unread mails
- show / hide Thunderbird (minimize)
- minimizing hides to tray
- minimize on startup

## Binaries (System)

These packages will install the Thunderbird Add-on and companion app system wide.  
Root credentials are required.

### openSuSE
#### Leap 15.1

```bash
sudo zypper ar -f https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/openSUSE_Leap_15.1/ SysTray-X
sudo zypper in systray-x
```

#### Leap 15.2

```bash
sudo zypper ar -f https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/openSUSE_Leap_15.2/ SysTray-X
sudo zypper in systray-x
```

#### Tumbleweed

```bash
sudo zypper ar -f https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/openSUSE_Tumbleweed/ SysTray-X
sudo zypper in systray-x
```

#### SLE 15

```bash
sudo zypper ar -f https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/openSUSE_SLE_15_SP1/ SysTray-X
sudo zypper in systray-x
```

### xUbuntu

#### 19.10

```bash
wget -q https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/xUbuntu_19.10/Release.key
sudo apt-key add Release.key
sudo bash -c "echo 'deb https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/xUbuntu_19.10 ./" > /etc/apt/source.list.d/systray-x.list'```
sudo apt update
sudo apt install systray-x
```

#### 18.04 LTS

```bash
wget -q https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/xUbuntu_18.04/Release.key
sudo apt-key add Release.key
sudo bash -c 'echo "deb https://download.opensuse.org/repositories/home:/Ximi1970:/Mozilla:/Add-ons/xUbuntu_18.04 ./" > /etc/apt/source.list.d/systray-x.list'```
sudo apt update
sudo apt install systray-x
```

## Binaries (User)

User installable package.  
No root credentials required.  

Download the installer here:

[Companion installer](https://github.com/Ximi1970/systray-x/releases)

And install the add-on using the Thunderbird Add-on / Extensions store.

## Building

### Linux

Clone the repository:
```bash
git clone https://github.com/Ximi1970/systray-x.git
```

Requirements:
  - Fedora/Centos/RHEL:

    ```dnf install qt5-qtbase-devel```
  - Debian/Ubuntu:

    ```apt install zip git g++ make qt5-default qtbase5-dev```

Build:
```bash
cd systray-x
make
```

...


### Windows

Install:
- [Visual Studio Express 2017](https://aka.ms/vs/15/release/vs_WDExpress.exe)
- [Visual Code Studio](https://code.visualstudio.com/)
- [Git for Windows](https://gitforwindows.org/)
- [TortoiseGit](https://tortoisegit.org/)
- [PuTTY](https://www.putty.org/)
- [Qt](https://www.qt.io/download-thank-you?os=windows&hsLang=en)

Clone the repository using TortoiseGit:

...


### Remarks

Branches:  

master      : Should be stable and working for all systems  
develop     : Working but maybe not for all systems  
feature-xxx : Experimental  

## Contributers

Luigi Baldoni \<aloisio@gmx.com\>		: Initial setup of the OpenSuSE Build Service rpm package.



## Donations
To support this project, you can make a donation to its current maintainer:  

[![paypal](https://github.com/Ximi1970/Donate/blob/master/paypal_btn_donateCC_LG_2.gif)](https://paypal.me/Ximi1970)
[![bitcoin-qrcode-black](https://github.com/Ximi1970/Donate/blob/master/bitcoin-donate-qrcode-black.png)](https://raw.githubusercontent.com/Ximi1970/Donate/master/bitcoin-address.txt)
