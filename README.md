# dutool

A command line tool to run specified programs that require configuration with secrets in unsafe environment

## Idea and plan

Idea is simple: for example, run `dutool run vpn`, it asks for your password, decrypts configuration for your VPN client, and runs the binary using this configuration.

Plan: dependency-less C program, that's a single binary, handles encryption (AES256) of configuration files, holds everything in database, and makes sure that your files always have just enough permission to work (a-rwx, u+r). Everything has to be easy to backup, and safe enough to send with smile to threat actor.

UI has to be simple, for example:

```
dutool - shows help
dutool set password - sets global password, asked on every "run"
dutool new ABC - goes step-by-step with user, defining new program to run
dutool remove ABC - you know what it does
dutool run ABC - yeah, you get the idea
dutool panic - try to overwrite every single byte of data, no questions asked
```

Database, configuration files, and anything else needed to run should be kept in `~/.config/dutool` directory with minimal permissions.

No binary releases. Code has to be easy to build. Stable version on branch `master`, anything else is unsafe/untested/in-dev.
