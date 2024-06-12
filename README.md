# LINIX DEVICE DRIVERS

## dryinit_module
Sample module which allows to see if you are able to load and unload module.

* Build, install and boot kernel from kernel.org -> tested on 6.9.3
* ```cd dryinit_module && make```
* ```sudo insmod dryinit-module.ko```
* ```sudo rmsmod dryinit-module.ko```
* ```sudo dmesg```

Shall see
```
[  119.001055] Hello, world
[  200.727763] Goodbye, cruel world
```
Trace dmsg/syslog
```
tail -f /var/log/syslog 
```

Testing
```Python3
f = open('/dev/scull0', 'w')
f.write('TEST)
```

### Current issue
python
```Python3
Python 3.10.12 (main, Nov 20 2023, 15:14:05) [GCC 11.4.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> f = open('/dev/scull0', 'w')
Killed
```

/var/log/syslog 
```
Jun 12 20:27:28 user geoclue[1533]: Service not used for 60 seconds. Shutting down..
Jun 12 20:27:28 user systemd[1]: geoclue.service: Deactivated successfully.
Jun 12 20:27:49 user systemd[1828]: Started Application launched by gnome-session-binary.
Jun 12 20:27:49 user systemd[1828]: Started Application launched by gnome-session-binary.
Jun 12 20:27:52 user ubuntu-appindicators@ubuntu.com[1997]: unable to update icon for software-update-available
Jun 12 20:27:52 user ubuntu-appindicators@ubuntu.com[1997]: unable to update icon for livepatch
Jun 12 20:27:57 user dbus-daemon[1863]: [session uid=1000 pid=1863] Activating via systemd: service name='org.freedesktop.Tracker3.Miner.Extract' unit='tracker-extract-3.service' requested by ':1.80' (uid=1000 pid=2435 comm="/usr/libexec/tracker-miner-fs-3 ")
Jun 12 20:27:57 user systemd[1828]: Starting Tracker metadata extractor...
Jun 12 20:27:57 user dbus-daemon[1863]: [session uid=1000 pid=1863] Successfully activated service 'org.freedesktop.Tracker3.Miner.Extract'
Jun 12 20:27:57 user systemd[1828]: Started Tracker metadata extractor.
Jun 12 20:29:46 user gnome-shell[1997]: libinput error: event8  - Dell Computer Corp Dell Laser Mouse MS3220: client bug: event processing lagging behind by 71ms, your system is too slow
Jun 12 20:29:46 user kernel: [  196.880525] scull initialized
Jun 12 20:29:46 user kernel: [  225.226833] BUG: kernel NULL pointer dereference, address: 0000000000000000
Jun 12 20:29:46 user kernel: [  225.226843] #PF: supervisor write access in kernel mode
Jun 12 20:29:46 user kernel: [  225.226846] #PF: error_code(0x0002) - not-present page
Jun 12 20:29:46 user kernel: [  225.226848] PGD 0 P4D 0 
Jun 12 20:29:46 user kernel: [  225.226853] Oops: 0002 [#1] PREEMPT SMP PTI
Jun 12 20:29:46 user kernel: [  225.226857] CPU: 1 PID: 5486 Comm: python3 Tainted: G           OE      6.9.3 #1
Jun 12 20:29:46 user kernel: [  225.226862] Hardware name: Dell Inc. Latitude 5480/015DR5, BIOS 1.31.0 07/03/2023
Jun 12 20:29:46 user kernel: [  225.226864] RIP: 0010:__down_common+0x57/0x220
Jun 12 20:29:46 user kernel: [  225.226873] Code: c0 0f 1f 44 00 00 49 8b 45 10 48 8d 4c 24 10 41 89 de 49 8d 55 08 49 89 4d 10 81 e3 01 01 00 00 48 89 44 24 18 48 89 54 24 10 <48> 89 08 44 89 f0 83 e0 01 c6 44 24 28 00 65 4c 8b 3d a3 49 2d 61
Jun 12 20:29:46 user kernel: [  225.226876] RSP: 0018:ffffa7ce0301baf0 EFLAGS: 00010002
Jun 12 20:29:46 user kernel: [  225.226879] RAX: 0000000000000000 RBX: 0000000000000001 RCX: ffffa7ce0301bb00
Jun 12 20:29:46 user kernel: [  225.226882] RDX: ffff9b6087aa0428 RSI: 0000000000000001 RDI: ffff9b6087aa0420
Jun 12 20:29:46 user kernel: [  225.226884] RBP: ffffa7ce0301bb60 R08: 0000000000000000 R09: 0000000000000000
Jun 12 20:29:46 user kernel: [  225.226886] R10: 0000000000000000 R11: 0000000000000000 R12: 7fffffffffffffff
Jun 12 20:29:46 user kernel: [  225.226888] R13: ffff9b6087aa0420 R14: 0000000000000001 R15: ffff9b61615f3698
Jun 12 20:29:46 user kernel: [  225.226891] FS:  0000735d9a90e000(0000) GS:ffff9b61a6480000(0000) knlGS:0000000000000000
Jun 12 20:29:46 user kernel: [  225.226894] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
Jun 12 20:29:46 user kernel: [  225.226896] CR2: 0000000000000000 CR3: 000000018415a006 CR4: 00000000003706f0
Jun 12 20:29:46 user kernel: [  225.226899] DR0: 0000000000000000 DR1: 0000000000000000 DR2: 0000000000000000
Jun 12 20:29:46 user kernel: [  225.226901] DR3: 0000000000000000 DR6: 00000000fffe0ff0 DR7: 0000000000000400
Jun 12 20:29:46 user kernel: [  225.226904] Call Trace:
Jun 12 20:29:46 user kernel: [  225.226906]  <TASK>
Jun 12 20:29:46 user kernel: [  225.226910]  ? show_regs+0x71/0x90
Jun 12 20:29:46 user kernel: [  225.226917]  ? __die+0x25/0x80
Jun 12 20:29:46 user kernel: [  225.226922]  ? page_fault_oops+0x151/0x530
Jun 12 20:29:46 user kernel: [  225.226928]  ? d_absolute_path+0x59/0xb0
Jun 12 20:29:46 user kernel: [  225.226934]  ? do_user_addr_fault+0x341/0x6d0
Jun 12 20:29:46 user kernel: [  225.226939]  ? exc_page_fault+0x83/0x1b0
Jun 12 20:29:46 user kernel: [  225.226944]  ? asm_exc_page_fault+0x27/0x30
Jun 12 20:29:46 user kernel: [  225.226951]  ? __down_common+0x57/0x220
Jun 12 20:29:46 user kernel: [  225.226957]  ? dput+0x40/0x1b0
Jun 12 20:29:46 user kernel: [  225.226965]  __down_interruptible+0x1d/0x30
Jun 12 20:29:46 user kernel: [  225.226970]  down_interruptible+0x63/0x70
Jun 12 20:29:46 user kernel: [  225.226975]  scull_open+0x50/0x90 [scull]
Jun 12 20:29:46 user kernel: [  225.226982]  chrdev_open+0xcd/0x250
Jun 12 20:29:46 user kernel: [  225.226986]  ? __pfx_chrdev_open+0x10/0x10
Jun 12 20:29:46 user kernel: [  225.226991]  do_dentry_open+0x16f/0x580
Jun 12 20:29:46 user kernel: [  225.226996]  vfs_open+0x33/0x50
Jun 12 20:29:46 user kernel: [  225.226999]  path_openat+0xaa7/0x10b0
Jun 12 20:29:46 user kernel: [  225.227006]  do_filp_open+0xb0/0x160
Jun 12 20:29:46 user kernel: [  225.227012]  ? alloc_fd+0xac/0x1a0
Jun 12 20:29:46 user kernel: [  225.227017]  do_sys_openat2+0xa1/0xd0
Jun 12 20:29:46 user kernel: [  225.227022]  __x64_sys_openat+0x55/0xa0
Jun 12 20:29:46 user kernel: [  225.227025]  x64_sys_call+0x1ea4/0x2660
Jun 12 20:29:46 user kernel: [  225.227030]  do_syscall_64+0x72/0x130
Jun 12 20:29:46 user kernel: [  225.227035]  ? do_user_addr_fault+0x373/0x6d0
Jun 12 20:29:46 user kernel: [  225.227039]  ? irqentry_exit_to_user_mode+0x63/0x190
Jun 12 20:29:46 user kernel: [  225.227043]  ? irqentry_exit+0x43/0x50
Jun 12 20:29:46 user kernel: [  225.227047]  ? exc_page_fault+0x94/0x1b0
Jun 12 20:29:46 user kernel: [  225.227051]  entry_SYSCALL_64_after_hwframe+0x76/0x7e
Jun 12 20:29:46 user kernel: [  225.227056] RIP: 0033:0x735d9a71453b
Jun 12 20:29:46 user kernel: [  225.227059] Code: 25 00 00 41 00 3d 00 00 41 00 74 4b 64 8b 04 25 18 00 00 00 85 c0 75 67 44 89 e2 48 89 ee bf 9c ff ff ff b8 01 01 00 00 0f 05 <48> 3d 00 f0 ff ff 0f 87 91 00 00 00 48 8b 54 24 28 64 48 2b 14 25
Jun 12 20:29:46 user kernel: [  225.227063] RSP: 002b:00007ffe4d509430 EFLAGS: 00000246 ORIG_RAX: 0000000000000101
Jun 12 20:29:46 user kernel: [  225.227067] RAX: ffffffffffffffda RBX: 0000735d9a90df80 RCX: 0000735d9a71453b
Jun 12 20:29:46 user kernel: [  225.227070] RDX: 0000000000080241 RSI: 0000735d99ea4350 RDI: 00000000ffffff9c
Jun 12 20:29:46 user kernel: [  225.227073] RBP: 0000735d99ea4350 R08: 0000000000000000 R09: 0000000000000000
Jun 12 20:29:46 user kernel: [  225.227075] R10: 00000000000001b6 R11: 0000000000000246 R12: 0000000000080241
Jun 12 20:29:46 user kernel: [  225.227078] R13: 0000000000080241 R14: 0000735d99ea3670 R15: 0000000000000001
Jun 12 20:29:46 user kernel: [  225.227083]  </TASK>
Jun 12 20:29:46 user kernel: [  225.227084] Modules linked in: scull(E) ccm bnep snd_sof_pci_intel_skl snd_sof_intel_hda_common soundwire_intel snd_sof_intel_hda_mlink soundwire_cadence snd_sof_intel_hda snd_sof_pci snd_sof_xtensa_dsp iwlmvm snd_sof intel_tcc_cooling x86_pkg_temp_thermal snd_sof_utils soundwire_generic_allocation soundwire_bus intel_powerclamp snd_soc_avs binfmt_misc mac80211 snd_soc_hda_codec mei_hdcp intel_rapl_msr snd_soc_skl nls_iso8859_1 mei_pxp snd_soc_hdac_hda snd_hda_ext_core snd_soc_sst_ipc snd_soc_sst_dsp coretemp dell_rbtn kvm_intel dell_laptop snd_soc_acpi_intel_match snd_soc_acpi snd_hda_codec_hdmi kvm snd_soc_core libarc4 snd_ctl_led ledtrig_audio dell_smm_hwmon iwlwifi snd_hda_codec_realtek snd_compress ac97_bus snd_hda_codec_generic snd_hda_scodec_component snd_pcm_dmaengine snd_hda_intel rapl dell_wmi snd_intel_dspcfg intel_cstate snd_usb_audio snd_intel_sdw_acpi dell_smbios dcdbas snd_usbmidi_lib snd_ump dell_wmi_ddv snd_hda_codec dell_wmi_descriptor cfg80211 btusb lis3lv02d_i2c wmi_bmof snd_seq_midi serio_raw
Jun 12 20:29:46 user kernel: [  225.227157]  intel_wmi_thunderbolt snd_seq_midi_event lis3lv02d btrtl btintel snd_hda_core btbcm uvcvideo snd_rawmidi snd_seq snd_hwdep snd_pcm videobuf2_vmalloc btmtk uvc videobuf2_memops snd_seq_device snd_timer videobuf2_v4l2 input_leds bluetooth snd videodev processor_thermal_device_pci_legacy processor_thermal_device processor_thermal_wt_hint soundcore processor_thermal_rfim processor_thermal_rapl videobuf2_common joydev mei_me ecdh_generic intel_rapl_common mc mei processor_thermal_wt_req processor_thermal_power_floor ecc processor_thermal_mbox intel_xhci_usb_role_switch intel_soc_dts_iosf intel_pch_thermal intel_pmc_core intel_vsec pmt_telemetry int3403_thermal dell_smo8800 intel_hid int3400_thermal acpi_pad int340x_thermal_zone pmt_class sparse_keymap acpi_thermal_rel mac_hid sch_fq_codel msr evdi(OE) parport_pc ppdev lp parport efi_pstore ip_tables x_tables autofs4 dm_crypt usbhid r8153_ecm cdc_ether usbnet r8152 mii i915 drm_buddy i2c_algo_bit ttm drm_display_helper cec hid_alps rc_core hid_generic
Jun 12 20:29:46 user kernel: [  225.227245]  i2c_hid_acpi drm_kms_helper i2c_hid rtsx_pci_sdmmc crct10dif_pclmul hid crc32_pclmul polyval_clmulni polyval_generic ghash_clmulni_intel sha256_ssse3 sha1_ssse3 e1000e drm rtsx_pci i2c_i801 ahci i2c_smbus libahci video xhci_pci xhci_pci_renesas intel_lpss_pci intel_lpss idma64 wmi aesni_intel crypto_simd cryptd
Jun 12 20:29:46 user kernel: [  225.227269] CR2: 0000000000000000
Jun 12 20:29:46 user kernel: [  225.227272] ---[ end trace 0000000000000000 ]---
Jun 12 20:29:46 user kernel: [  226.500837] RIP: 0010:__down_common+0x57/0x220
Jun 12 20:29:46 user kernel: [  226.500864] Code: c0 0f 1f 44 00 00 49 8b 45 10 48 8d 4c 24 10 41 89 de 49 8d 55 08 49 89 4d 10 81 e3 01 01 00 00 48 89 44 24 18 48 89 54 24 10 <48> 89 08 44 89 f0 83 e0 01 c6 44 24 28 00 65 4c 8b 3d a3 49 2d 61
Jun 12 20:29:46 user kernel: [  226.500867] RSP: 0018:ffffa7ce0301baf0 EFLAGS: 00010002
Jun 12 20:29:46 user kernel: [  226.500872] RAX: 0000000000000000 RBX: 0000000000000001 RCX: ffffa7ce0301bb00
Jun 12 20:29:46 user kernel: [  226.500874] RDX: ffff9b6087aa0428 RSI: 0000000000000001 RDI: ffff9b6087aa0420
Jun 12 20:29:46 user kernel: [  226.500876] RBP: ffffa7ce0301bb60 R08: 0000000000000000 R09: 0000000000000000
Jun 12 20:29:46 user kernel: [  226.500878] R10: 0000000000000000 R11: 0000000000000000 R12: 7fffffffffffffff
Jun 12 20:29:46 user kernel: [  226.500880] R13: ffff9b6087aa0420 R14: 0000000000000001 R15: ffff9b61615f3698
Jun 12 20:29:46 user kernel: [  226.500882] FS:  0000735d9a90e000(0000) GS:ffff9b61a6480000(0000) knlGS:0000000000000000
Jun 12 20:29:46 user kernel: [  226.500885] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
Jun 12 20:29:46 user kernel: [  226.500888] CR2: 0000000000000000 CR3: 000000018415a006 CR4: 00000000003706f0
Jun 12 20:29:46 user kernel: [  226.500890] DR0: 0000000000000000 DR1: 0000000000000000 DR2: 0000000000000000
Jun 12 20:29:46 user kernel: [  226.500892] DR3: 0000000000000000 DR6: 00000000fffe0ff0 DR7: 0000000000000400
Jun 12 20:29:46 user kernel: [  226.500895] note: python3[5486] exited with irqs disabled
Jun 12 20:29:46 user kernel: [  226.500978] note: python3[5486] exited with preempt_count 1
Jun 12 20:30:01 user CRON[5786]: (root) CMD ([ -x /etc/init.d/anacron ] && if [ ! -d /run/systemd/system ]; then /usr/sbin/invoke-rc.d anacron start >/dev/null; fi)
Jun 12 20:30:30 user wpa_supplicant[1080]: wlp2s0: CTRL-EVENT-SIGNAL-CHANGE above=0 signal=-66 noise=9999 txrate=0
Jun 12 20:30:53 user systemd[1]: Started Run anacron jobs.
Jun 12 20:30:53 user anacron[5832]: Anacron 2.3 started on 2024-06-12
Jun 12 20:30:53 user anacron[5832]: Normal exit (0 jobs run)
Jun 12 20:30:53 user systemd[1]: anacron.service: Deactivated successfully.
Jun 12 20:30:54 user wpa_supplicant[1080]: wlp2s0: CTRL-EVENT-SIGNAL-CHANGE above=1 signal=-61 noise=9999 txrate=0
```
## sample_program
User space running programs