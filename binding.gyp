{
  "targets": [
    {
      "target_name": "canvas-skia",
      "sources": [
        "src/addon.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}

