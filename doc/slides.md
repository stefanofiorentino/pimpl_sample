<!-- $size: 16:9 -->

<style>
.slide_inner
{
    height: 600px;
}

footer
{
    text-align: right;
    width: 92%;
    bottom: 10px !important;
	left: 90px !important;
}

.points
{
    font-size: 115%;
    margin-left: -40px;
    margin-right: -40px;
}

.inline-link
{
    font-size: 50%;
    margin-top: -2.6em;
    margin-right: 10px;
    text-align: right;
    font-weight: bold;
}

.intxt
{
	font-size: 75%;
    position: absolute;
    top: -80px;
    left: -65px;
    color: grey;
}

.slide_page
{
	top: 0px;
    right: 20px !important;
}
</style>

<span style="font-size: 150%">

<br>

<center style="margin-top: -70px !important">

# Implementation hiding

</center>

<br>

<div style="float: left; font-size: 70%">

## **Stefano Fiorentino**

stefano.fiore84@gmail.com
[@fiorentinoing](https://twitter.com/fiorentinoing)

</div>

<div style="float: right; font-size: 70%; text-align: right; margin-top: -0px !important">

## pImpl idiom

09/01/2019
Milan, IT

</div>

</span>

---

<!-- page_number: true -->
<!-- footer: stefanofiorentino.it | stefano.fiore84@gmail.com | @fiorentinoing -->

# Introduction
## what is this talk about?

<div class="points">

* ship a dynamic library with minimum public information about implementation
	* the header files shipped in the package show only the interface (not the implementation)
* this is very useful if you want to change the implementation iterating over relases without forcing customer to relink their code against your library
	* public APIs (signatures) keep same form over releases

</div>

---

# Introduction

<div class="points">

* the client of the lib can just call the `solution` functionality as follows:

```cpp
// main.cpp
#include "hider.hpp"

int main()
{
    hider h;
    h.solution();
    return 0;
}
```

</div>

---

# The public APIs

<div class="points">

* the (public) header file you ship with the lib:

```cpp
// hider.hpp
#pragma once
#include <memory>

class hider
{
public:
    hider();
    ~hider();
    void solution();
private:
    class hidden;
    std::unique_ptr<hidden> pHidden;
};
```

</div>

---

# The private implementation

<div class="points">

* the (private) cpp file you hide inside the (stripped) lib:

```cpp
// hidden.impl.cpp
#include "hider.hpp"
struct hider::hidden
{
    void custom_solution() { std::puts(__PRETTY_FUNCTION__); }
};
hider::hider() : pHidden{ new hidden{ } } { }
hider::~hider() = default;
void hider::solution()
{
    pHidden->custom_solution();
}

```

</div>

---

# What do you ship?

<div class="points">

* the (public) header file: hider.hpp
* the (stripped) lib file: libpimpl_sample_lib.so
	* in order to compile the objects you have to issue:
  ```bash
  g++ -g -fPIC -std=gnu++11 -o hidden.impl.cpp.o -c hidden.impl.cpp
  ```
	* in order to link the lib
  ```bash
  g++ -fPIC -shared -o libpimpl_sample_lib.so hidden.impl.cpp.o
  ```
  	* in order to strip the lib (otherwise everything is useless) 
  ```bash
  cp libpimpl_sample_lib.so libpimpl_sample_lib.so_nostrip
  strip libpimpl_sample_lib.so
  ```

</div>

---

<!-- page_number: false  -->

<center style="zoom:80%; font-size: 50px">

# Thanks!

https://stefanofiorentino.it

stefano.fiore84@gmail.com

[@fiorentinoing](https://twitter.com/fiorentinoing)

<small>

https://github.com/stefanofiorentino/pimpl_sample

</small>

</center>
