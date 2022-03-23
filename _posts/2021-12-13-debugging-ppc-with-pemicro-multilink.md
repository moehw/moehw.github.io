---
layout: post
title:  "Debugging PPC with PEmicro MultiLink"
image: ''
date:   2021-12-13 10:03:49 +0300
categories: [howto]
tags: [debug, multilink, ppc]
---

Experience in debugging a device with a MPC5xxx from NXP (PPC architecture).

It had approximately the following debug connector:

![mpc5566 connector](/assets/img/posts/mpc5566-connector.png)

And there was access to the PEmicro Multilink Universal. Software [S32DS](https://www.nxp.com/design/software/development-software/s32-design-studio-ide:S32-DESIGN-STUDIO-IDE) from NXP can work with it (to download it you can use creds from [BugMeNot](http://bugmenot.com/view/nxp.com)).

**But** this IDE itself does not allow you to conveniently work for the purpose of debugging and dumping the firmware, so it is more convenient to take its individual plugins and work with them.

If you have time and disk space, you can install the IDE itself and then use the plugins. This is a more reliable way. If there is no time, then you can follow this tutorial completely.

## Preparing for debugging

### For Windows

Tested on a Windows 10 x64 virtual machine (VM).

Drivers and plugins: [here](https://github.com/moehw/mpc5xxx-multilink-debug/releases)

1. Attach PEMicro MultiLink.
2. Throw it to the VM, if it is a VM.
3. Unpack the archive. Copy `PEMicro` folder to `C:\`
4. Open console as Administrator ( `Win + X` , release and then `A` )
5. Enter the following commands, agreeing to the installation:

```powershell
C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\wdreg_gui.exe -inf C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\pemicrowindrvr.inf -log C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\pe_winusb_interface.log install
 
C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\wdreg_gui.exe -inf C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\pe_winusb_interface.inf -log C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\pe_winusb_interface.log install
 
C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\wdreg_gui.exe -inf C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\osbdm\pe_libusb_interface.inf -log C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\pe_winusb_interface.log install
 
C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\wdreg_gui.exe -inf C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\osbdm\serialcdc_interface.inf -log C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\pe_winusb_interface.log install
 
cp -Path C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\windriver\redist* -Destination C:\Windows\System32
 
cp -Path C:\PEMicro\PEDrivers\supportfiles\Drivers_12_7_0\osbdm\redist\* -Destination C:\Windows\System32
```

{:start="6"}
6. Viewing the list of targets and selecting one of them (for example, MPC5606B):

```powershell
C:\PEMicro\com.pemicro.debug.gdbjtag.ppc_1.8.7.201906071634\win32\pegdbserver_power_console.exe -devicelist
```

{:start="7"}
7. Enable target device.
8. Launching the plugin (specifying the desired target):

```powershell
C:\PEMicro\com.pemicro.debug.gdbjtag.ppc_1.8.7.201906071634\win32\pegdbserver_power_console.exe -startserver -singlesession -useexternalip -device=MPC5606B
```

{:start="9"}
9. After that, `gdbserver` should start:

![mpc5566 gdbserver](/assets/img/posts/mpc5566-gdbserver.png)

## Connecting to gdbserver

Port `7224` is used to connect to `gdbserver` (by default).

You can connect from the host OS if everything is running in a VM with a network interface.

Use:

* `gdb-multiarch` - some configuration required, but breakpoints work anyway
* `gdb-powerpc-eabivle` (from Release page or anywhere else)
