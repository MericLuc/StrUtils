TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = str-utils-lib \
          str-utils-test
app.depends = str-utils-lib
