project('myapp', 'c', default_options: ['c_std=c17', 'warning_level=2'])

inc = include_directories('include')
util = static_library('util', 'src/util.c', include_directories: inc)
executable('app', 'src/main.c', include_directories: inc, link_with: util)
