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
[ 2289.993208] scull initialized
[ 2313.033471] BUG: kernel NULL pointer dereference, address: 0000000000000000
[ 2313.033485] #PF: supervisor write access in kernel mode
[ 2313.033490] #PF: error_code(0x0002) - not-present page
[ 2313.033495] PGD 800000010ac06067 P4D 800000010ac06067 PUD 10469e067 PMD 0 
[ 2313.033507] Oops: 0002 [#1] PREEMPT SMP PTI
[ 2313.033514] CPU: 3 PID: 20780 Comm: python3 Tainted: G            E      6.9.6 #1
[ 2313.033521] Hardware name: Apple Inc. x/Mac-x, BIOS 481.0.0.0.0 01/12/2023
[ 2313.033526] RIP: 0010:__down_common+0x6c/0x210
[ 2313.033538] Code: 54 24 08 48 c7 44 24 28 00 00 00 00 65 4c 8b 3d 0a 78 42 57 41 81 e5 01 01 00 00 48 89 44 24 18 49 89 4c 24 10 48 89 54 24 10 <48> 89 08 44 89 f0 83 e0 01 4c 89 7c 24 20 c6 44 24 28 00 89 44 24
[ 2313.033544] RSP: 0018:ffffa3d94236f9d0 EFLAGS: 00010002
[ 2313.033551] RAX: 0000000000000000 RBX: 7fffffffffffffff RCX: ffffa3d94236f9e0
[ 2313.033556] RDX: ffff9194e72ed428 RSI: 0000000000000001 RDI: ffff9194e72ed420
[ 2313.033560] RBP: ffffa3d94236fa40 R08: 0000000000000000 R09: 0000000000000000
[ 2313.033565] R10: 0000000000000000 R11: 0000000000000000 R12: ffff9194e72ed420
[ 2313.033569] R13: 0000000000000001 R14: 0000000000000001 R15: ffff9194e13628c0
[ 2313.033573] FS:  0000710efc851080(0000) GS:ffff919626d80000(0000) knlGS:0000000000000000
[ 2313.033579] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[ 2313.033584] CR2: 0000000000000000 CR3: 0000000122740003 CR4: 00000000003706f0
[ 2313.033589] Call Trace:
[ 2313.033592]  <TASK>
[ 2313.033600]  ? show_regs+0x6c/0x80
[ 2313.033611]  ? __die+0x24/0x80
[ 2313.033620]  ? page_fault_oops+0x175/0x5a0
[ 2313.033630]  ? poll_freewait+0x42/0xa0
[ 2313.033637]  ? do_user_addr_fault+0x306/0x6f0
[ 2313.033646]  ? exc_page_fault+0x82/0x1b0
[ 2313.033655]  ? asm_exc_page_fault+0x27/0x30
[ 2313.033667]  ? __down_common+0x6c/0x210
[ 2313.033680]  __down_interruptible+0x1d/0x30
[ 2313.033688]  down_interruptible+0x5d/0x70
[ 2313.033696]  scull_open+0x46/0x70 [scull]
[ 2313.033708]  chrdev_open+0xd2/0x250
[ 2313.033716]  ? __pfx_chrdev_open+0x10/0x10
[ 2313.033722]  do_dentry_open+0x21d/0x570
[ 2313.033730]  vfs_open+0x33/0x50
[ 2313.033737]  path_openat+0xaf8/0x1170
[ 2313.033745]  do_filp_open+0xc0/0x170
[ 2313.033755]  do_sys_openat2+0xb3/0xe0
[ 2313.033762]  ? __lruvec_stat_mod_folio+0x70/0xc0
[ 2313.033773]  __x64_sys_openat+0x55/0xa0
[ 2313.033779]  x64_sys_call+0x1eb8/0x25c0
[ 2313.033786]  do_syscall_64+0x7e/0x180
[ 2313.033792]  ? __handle_mm_fault+0xc37/0xeb0
[ 2313.033801]  ? __count_memcg_events+0x6b/0x110
[ 2313.033809]  ? count_memcg_events.constprop.0+0x2a/0x50
[ 2313.033817]  ? handle_mm_fault+0xaf/0x330
[ 2313.033823]  ? do_user_addr_fault+0x339/0x6f0
[ 2313.033832]  ? irqentry_exit_to_user_mode+0x76/0x270
[ 2313.033839]  ? irqentry_exit+0x43/0x50
[ 2313.033846]  ? exc_page_fault+0x93/0x1b0
[ 2313.033854]  entry_SYSCALL_64_after_hwframe+0x76/0x7e
[ 2313.033862] RIP: 0033:0x710efc71b175
[ 2313.033868] Code: 83 e2 40 75 50 89 f0 f7 d0 a9 00 00 41 00 74 45 80 3d de fe 0e 00 00 74 60 89 da 4c 89 e6 bf 9c ff ff ff b8 01 01 00 00 0f 05 <48> 3d 00 f0 ff ff 0f 87 7f 00 00 00 48 8b 55 b8 64 48 2b 14 25 28
[ 2313.033874] RSP: 002b:00007ffee7950500 EFLAGS: 00000202 ORIG_RAX: 0000000000000101
[ 2313.033880] RAX: ffffffffffffffda RBX: 0000000000080241 RCX: 0000710efc71b175
[ 2313.033884] RDX: 0000000000080241 RSI: 0000710efbe389b0 RDI: 00000000ffffff9c
[ 2313.033888] RBP: 00007ffee7950570 R08: 0000000000000000 R09: 0000000000000000
[ 2313.033892] R10: 00000000000001b6 R11: 0000000000000202 R12: 0000710efbe389b0
[ 2313.033896] R13: 0000710efc850ff8 R14: 00000000ffffffff R15: 0000710efbe21870
[ 2313.033903]  </TASK>
[ 2313.033907] Modules linked in: scull(E) rfcomm snd_seq_dummy snd_hrtimer qrtr cmac snd_hda_codec_hdmi algif_hash algif_skcipher af_alg bnep i915 brcmfmac_wcc intel_rapl_msr intel_rapl_common cmdlinepart spi_nor x86_pkg_temp_thermal mtd intel_powerclamp coretemp kvm_intel spi_intel_platform spi_intel mei_hdcp mei_pxp joydev snd_hda_codec_cirrus brcmfmac snd_hda_codec_generic kvm btusb brcmutil snd_hda_intel btrtl snd_seq_midi snd_intel_dspcfg applesmc cfg80211 snd_intel_sdw_acpi snd_seq_midi_event snd_hda_codec btintel snd_rawmidi binfmt_misc snd_hda_core btbcm rapl btmtk i2c_i801 intel_cstate drm_buddy mei_me snd_seq lpc_ich intel_pch_thermal snd_hwdep i2c_smbus bluetooth ttm spi_pxa2xx_pci snd_pcm dw_dmac_pci mei nls_iso8859_1 drm_display_helper snd_seq_device bcm5974 ecdh_generic cec snd_timer ecc acpi_als snd rc_core industrialio_triggered_buffer sbs kfifo_buf sbshc i2c_algo_bit industrialio soundcore input_leds apple_mfi_fastcharge mac_hid msr parport_pc ppdev lp parport efi_pstore nfnetlink dmi_sysfs ip_tables
[ 2313.034011]  x_tables autofs4 dm_crypt hid_apple hid_generic usbhid uas hid usb_storage thunderbolt crct10dif_pclmul crc32_pclmul polyval_clmulni ahci polyval_generic xhci_pci ghash_clmulni_intel sha256_ssse3 sha1_ssse3 libahci xhci_pci_renesas applespi spi_pxa2xx_platform video dw_dmac dw_dmac_core wmi aesni_intel crypto_simd cryptd
[ 2313.034042] CR2: 0000000000000000
[ 2313.034046] ---[ end trace 0000000000000000 ]---
[ 2313.464180] RIP: 0010:__down_common+0x6c/0x210
[ 2313.464190] Code: 54 24 08 48 c7 44 24 28 00 00 00 00 65 4c 8b 3d 0a 78 42 57 41 81 e5 01 01 00 00 48 89 44 24 18 49 89 4c 24 10 48 89 54 24 10 <48> 89 08 44 89 f0 83 e0 01 4c 89 7c 24 20 c6 44 24 28 00 89 44 24
[ 2313.464193] RSP: 0018:ffffa3d94236f9d0 EFLAGS: 00010002
[ 2313.464196] RAX: 0000000000000000 RBX: 7fffffffffffffff RCX: ffffa3d94236f9e0
[ 2313.464197] RDX: ffff9194e72ed428 RSI: 0000000000000001 RDI: ffff9194e72ed420
[ 2313.464199] RBP: ffffa3d94236fa40 R08: 0000000000000000 R09: 0000000000000000
[ 2313.464200] R10: 0000000000000000 R11: 0000000000000000 R12: ffff9194e72ed420
[ 2313.464201] R13: 0000000000000001 R14: 0000000000000001 R15: ffff9194e13628c0
[ 2313.464203] FS:  0000710efc851080(0000) GS:ffff919626d80000(0000) knlGS:0000000000000000
[ 2313.464205] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[ 2313.464206] CR2: 0000000000000000 CR3: 0000000122740003 CR4: 00000000003706f0
[ 2313.464208] note: python3[20780] exited with irqs disabled
[ 2313.464249] note: python3[20780] exited with preempt_count 1
```


## sample_program
User space running programs