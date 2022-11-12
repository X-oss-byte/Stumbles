---
title: Stumpless
keywords: stumpless, c, logging, library, syslog, splunk, rsyslog, journald
last_updated: November 12, 2022
layout: default
---

# Stumpless at a glance
Stumpless is a C logging library built for high performance and a rich feature
set.

Stumpless offers a robust set of features to make logging in C faster and
easier:
 * cross-platform builds on Linux, Windows, Mac, Cygwin, and more
 * easy logging to network targets like Splunk or rsyslog servers
 * completely thread safe
 * can be adjusted or removed during compilation for zero runtime impact
 * interoperability with standard syslog daemons and library functions
 * an extensive test suite is run continuously to ensure proper functionality
 * localized for multiple languages &#127463;&#127479; &#127463;&#127468; &#127464;&#127475; &#127464;&#127487; &#127465;&#127466; &#127466;&#127480; &#127467;&#127479; &#127468;&#127479; &#127470;&#127475; &#127470;&#127481; &#127477;&#127473; &#127480;&#127466; &#127480;&#127472; &#127482;&#127480; 
   ([add yours!](https://github.com/goatshriek/stumpless/blob/latest/docs/localization.md))
 * easy-access
   [documentation](https://goatshriek.github.io/stumpless/docs/c/latest/index.html),
   [examples](https://github.com/goatshriek/stumpless/tree/latest/docs/examples),
   and [support](https://gitter.im/stumpless/community).

Check out our [vision](./vision.html) to see our ultimate goal! To see where
we're heading in the near future, check out the project
[roadmap](./roadmap.html).


# Examples and Documentation
If you're just looking to start out, then take a look at some of the examples
below. There is source code for each of these in the `docs/examples` folder of
the repository if you want to actually compile and run them.

 * [Basic Usage](./examples/basic.html)
 * [Using Severity Levels](./examples/severity_level.html)
 * [Working with Entries](./examples/entry.html)
 * [File Targets](./examples/file.html)
 * [Network Targets](./examples/network.html)
 * [Unix Socket Targets](./examples/socket.html)
 * [Stream Targets](./examples/stream.html)
 * [Windows Event Log Targets](./examples/wel.html)
 * [Custom Function Targets](./examples/function.html)
 * [C++ Bindings](./examples/cpp.html)

Detailed documentation of each function is included in the header files, and is
written using standard Doxygen syntax. You can generate the documentation
yourself with the `docs` build target, or you can look at one of the online
builds below:

 * [C Doxygen Documentation](./docs/c/latest/index.html)
 * [C++ Doxygen Documentation](./docs/cpp/latest/index.html)


# Source and Contributing
If you want to check out the source code and/or look into becoming a contributor
to stumpless, head over to the project's
[github repository](https://github.com/goatshriek/stumpless) to find out more!
