# canvas-skia

## Building Skia

```
brew install jpeg-turbo mozjpeg
```

And then: https://skia.org/user/build

Link brew installed libraries directly with `gn` flags. I spent 20 mins trying
to link against webp, but it did not work. In the end I disabled webp support.

```
bin/gn gen out/Shared --args='is_official_build=true skia_use_libwebp=false  \
is_component_build=true extra_cflags=["-I/usr/local/opt/jpeg-turbo/include", \
"-I/usr/local/opt/icu4c/include"]                                            \
extra_ldflags=["-L/usr/local/opt/jpeg-turbo/lib",                            \
"-L/usr/local/opt/icu4c/lib"]'
```

