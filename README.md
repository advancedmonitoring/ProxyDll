# Proxy dll

## Description

Here there are some exaples on writing proxy dll. Proxy dll is library that looks a like as some other library - it has same bitness, same name and same export functions. One of most important using of proxies is code injection into some executable file without modification via DLL hijack. Just place proxy dll of some system library near program and it will be loaded when program starts. You may execute your payload on DllEntry or on function calls.
All below examples given for version.dll.

## 01_TryHard

Direct approach. Write all functions bodies. Full prototypes, full original function call.

**Pros**

 * Program works normal

**Cons**

* So many code need to written
* All functions must have correct prototype

## 02_JustList

Adding naked declspec and jmps to reduce code size.

**Pros**

* Program works normal
* Almost no new code. Only needs is correctly declare export function (in def file and some occurrence at cpp)

**Cons**

* No x64 support in MSVS (since MSVS 2012, IIRC). Could be bypassed via g++, clang and so on.

## 03_LolNope

Refer all export functions as *void noop() {}* and terminate caller before any real call happens.

**Pros**

* No code for new fucntion at all - just add function name in def file.

**Cons**

* Program must be terminated before any actual code calls any function from dll (program will crash due to stack corrution).
