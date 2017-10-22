# Radar_Utility

WSR98D_CINRAD2WSR88D: This C++ program is used to transfer the WSR98D (CINRAD SA/SB) doppler radar level II data (reflectivity, velocity, spectral width) to the format of WSR88D, which could be directly ingested by ARPS data assimilation system.

Radar_Process: This Python program is used to plot the WSR98D (CINRAD SA/SB) doppler radar level II data (reflectivity), and applying adaptive Barnes interpolation, thinning, filter, super_obs. If you want to use this tool to create the radar.ob which could be ingested by WRFDA, you need to write the results according to the format of WRFDA.

Read_Radar: This program for Windows only. Read the doppler radar.

SA-SB-Radar: Another tool reading doppler radar