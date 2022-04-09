---
layout: post
title:  "UDS protocol header file for RE"
image: ''
date:   2021-11-30 21:22:07 +0300
categories: [howto]
tags: [automotive, rev]
---


## TL;DR

What I can contribute is this header file (to open it in IDA Pro and to use enums):
[uds.h](/assets/file/uds.h)

If you want to analyze exactly the part of the code with the processing of the UDS (a good attack vector), but there are no lines and logs, and, for example, the analysis of accesses to the memory area with the CAN (memory mapping) does not help... Then you can search for constant values in the code, that the most commonly implemented (may be *ECU Reset* (`0x11`) or response codes?), or that are visible in the sniffed traffic from/to the device.


## Intro

**UDS** (Unified Diagnostic Services) is a diagnostic protocol that is often used in electronic control units (ECUs) within automotive electronics. The whole description of protocol, list of Service ID, response codes, etc. are described in ISO 14229. In my work, more often I came across the use of UDS over CAN, there was also DoIP, but there are other options. The working principle and structure (in pictures!) can be viewed at the [link](https://www.csselectronics.com/pages/uds-protocol-tutorial-unified-diagnostic-services). To be honest, at the beginning I started to explain it by myself, but then I realize that another people do it very well :D


## Example

Let's say there is some firmware where you want to find the part with UDS processing. Let's open it in IDA Pro and try to find the immediate value `0x11` (`ECU Reset` and also `serviceNotSupported` values) through `"Search"` -> `"Immediate value..."` (`Alt` + `I`).

For some binary, I got a large list of instructions where this value is used, but the comparison instructions will be the most interesting places (in my case it's PPC instructions).

![Comparison instructions](/assets/img/posts/uds-cmp.png)

Not all cases found will suit me, but there should be some I need among them - so I go through them and look at the neighboring code.

After a while, I managed to find several interesting places. The first is the place where the switch-case is used.

![Switch-case - before](/assets/img/posts/uds-switch.png)

By applying the enum `UDS_sid` from the [header](/assets/file/uds.h), there is more confidence that these are the handlers we need, which can be checked further when reversing.

![Switch-case - after](/assets/img/posts/uds-switch-ready.png)

Do the same thing with a place suitable for `serviceNotSupported`.

![Function with negative answer - before](/assets/img/posts/uds-neg.png)

In enum `UDS_sid_resp` there are cases for `0x11`, `0x12`, `0x31` values. It becomes clear that this is some function for a negative answer:

![Function with negative answer - before](/assets/img/posts/uds-neg-ready.png)

So I'll just save that header here. It's handy for use in situations like this :)
