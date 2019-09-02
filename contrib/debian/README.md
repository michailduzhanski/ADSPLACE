
Debian
====================
This directory contains files used to package adsplaced/adsplace-qt
for Debian-based Linux systems. If you compile adsplaced/adsplace-qt yourself, there are some useful files here.

## adsplace: URI support ##


adsplace-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install adsplace-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your adsplaceqt binary to `/usr/bin`
and the `../../share/pixmaps/adsplace128.png` to `/usr/share/pixmaps`

adsplace-qt.protocol (KDE)

