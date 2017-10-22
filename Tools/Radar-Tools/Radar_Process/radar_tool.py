import numpy as np
from array import array
import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
import numpy.ma as ma 

class universal_radar_processor():
	def sa_sb_radar_read_dbz(self,file_path,n):
		#file_path: the absolute path to the file
		#n: the Nth evelation angle that you want
		# read data
		files=open(file_path,"r")
		data=np.asarray(array("B",files.read()))
		data=data.reshape([len(data)/2432,2432])
		# initialize some variables
		ElevationAngle=np.zeros([len(data),460])
		AzimuthAngle=np.zeros([len(data),460])
		rr_dbz=np.zeros([len(data),460])
		dbz=np.zeros([len(data),460])
		# read the variables
		count=0
		while count<len(data):
			AzimuthAngle[count,:]=(data[count,36]+256*data[count,37])/8.0*180/4096 #AzimuthAngle
			ElevationAngle[count,:]=(data[count,42]+256*data[count,43])/8.0*180/4096
			nbin_dbz=data[count,54]+256*data[count,55]				# dbz n bin
			ii=0
			while ii<460:
				rr_dbz[count,ii]=0.5+ii-1	# range
				if ii>nbin_dbz:		# dbz
					dbz[count,ii]=0
				else:
					if data[count,128+ii]==0: #no data
						dbz[count,ii]=0
					else:
						if data[count,128+ii]==1: #range ambiguity
							dbz[count,ii]=0
						else: # data is fine
							dbz[count,ii]=(data[count,128+ii]-2)/2.-32
				ii+=1
			count+=1
		tmp=0 
		while tmp<len(data):
			if data[tmp,44]>(n-1):
				break
			tmp+=1
		tmp01=tmp
		while tmp01<len(data):
			if data[tmp01,44]>n:
				break
			tmp01+=1
		EA=ElevationAngle[tmp:tmp01,:]
		AA=AzimuthAngle[tmp:tmp01,:]
		RR=rr_dbz[tmp:tmp01,:]
		DBZ=dbz[tmp:tmp01,:]
		return EA,AA,RR,DBZ

	def sa_sb_radar_read_vel(self,file_path,n):
		#file_path: the absolute path to the file
		#n: the Nth evelation angle that you want
		# read data
		files=open(file_path,"r")
		data=np.asarray(array("B",files.read()))
		data=data.reshape([len(data)/2432,2432])
		# initialize some variables
		ElevationAngle=np.zeros([len(data),920])
		AzimuthAngle=np.zeros([len(data),920])
		rr=np.zeros([len(data),920])
		vel=np.zeros([len(data),920])
		# read the variables
		count=0
		while count<len(data):
			AzimuthAngle[count,:]=(data[count,36]+256*data[count,37])/8.0*180/4096 #AzimuthAngle
			ElevationAngle[count,:]=(data[count,42]+256*data[count,43])/8.0*180/4096
			nbin_vel=data[count,56]+256*data[count,57]              # dbz n bin
			doppler_resolution=data[count,70]+256*data[count,71]
			ii=0
			while ii<920:
				rr[count,ii]=(0.5+ii-1)*0.25	# range
				if ii>nbin_vel:		# dbz
					vel[count,ii]=0
				else:
					if data[count,588+ii]==0: #no data
						vel[count,ii]=0
					else:
						if data[count,588+ii]==1: #range ambiguity
							vel[count,ii]=0
						else: # data is fine
							if doppler_resolution==2:
								vel[count,ii]=(data[count,588+ii]-2)/2.-63.5
							if doppler_resolution==4:
								vel[count,ii]=(data[count,588+ii]-2)-127
				ii+=1
			count+=1
		tmp=0 
		while tmp<len(data):
			if data[tmp,44]>(n-1):
				break
			tmp+=1
		tmp01=tmp
		while tmp01<len(data):
			if data[tmp01,44]>n:
				break
			tmp01+=1
		EA=ElevationAngle[tmp:tmp01,:]
		AA=AzimuthAngle[tmp:tmp01,:]
		RR=rr[tmp:tmp01,:]
		VEL=vel[tmp:tmp01,:]
		#return EA[:,:460],AA[:,:460],RR[:,:460],VEL[:,:460]
		return EA,AA,RR,VEL

	def sa_sb_radar_read_spectral_width(self,file_path,n):
		#file_path: the absolute path to the file
		#n: the Nth evelation angle that you want
		# read data
		files=open(file_path,"r")
		data=np.asarray(array("B",files.read()))
		data=data.reshape([len(data)/2432,2432])
		# the elevation angle
		if data[0,72]==11:
			phi=[0.50,0.50,1.45,1.45,2.40,3.35,4.30,5.25,6.2,7.5,8.7,10,12,14,16.7,19.5]
		if data[0,72]==21:
			phi=[0.50,0.50,1.45,1.45,2.40,3.35,4.30,6.00,9.00,14.6,19.5]
		if data[0,72]==31:
			phi=[0.50,0.50,1.50,1.50,2.50,2.50,3.50,4.50]
		if data[0,72]==32:
			phi=[0.50,0.50,2.50,3.50,4.50]
		# initialize some variables
		ElevationAngle=np.zeros([len(data),920])
		AzimuthAngle=np.zeros([len(data),920])
		rr=np.zeros([len(data),920])
		vel=np.zeros([len(data),920])
		# read the variables
		count=0
		while count<len(data):
			nthelevation=data[count,44]+256*data[count,45]				#the Nth elevation angle
			AzimuthAngle[count,:]=(data[count,36]+256*data[count,37])/8*180/4096 #AzimuthAngle
			ElevationAngle[count,:]=phi[nthelevation-1]
			nbin_vel=data[count,56]+256*data[count,57]              # dbz n bin
			ii=0
			while ii<920:
				rr[count,ii]=(0.5+ii-1)*0.25	# range
				if ii>nbin_vel:		# dbz
					vel[count,ii]=0
				else:
					if data[count,1508+ii]==0: #no data
						vel[count,ii]=0
					else:
						if data[count,1508+ii]==1: #range ambiguity
							vel[count,ii]=0
						else: # data is fine
							vel[count,ii]=(data[count,1508+ii]-2)/2.-63.5
				ii+=1
			count+=1
		tmp=0 
		while tmp<len(data):
			if data[tmp,44]>(n-1):
				break
			tmp+=1
		tmp01=tmp
		while tmp01<len(data):
			if data[tmp01,44]>n:
				break
			tmp01+=1
		EA=ElevationAngle[tmp:tmp01,:]
		AA=AzimuthAngle[tmp:tmp01,:]
		RR=rr[tmp:tmp01,:]
		VEL=vel[tmp:tmp01,:]
		return EA[:,:460],AA[:,:460],RR[:,:460],VEL[:,:460]

	def sph2cart(self,elevation,azimuth,r):
		ele,a= np.deg2rad([elevation,azimuth])
		x=r*np.cos(ele)*np.cos(a)
		y= r * np.cos(ele) * np.sin(a)
		z = r * np.sin(ele)
		return x,y,z
	
	def set_negative_nonprecipitation_echo_zero(self,DBZ,nn):
		mask=DBZ<0.0
		DBZ[mask]=0.0
		mask=DBZ<nn
		DBZ[mask]=0.0
		return DBZ
	
	def maskout(self,VAR,nn):
		mask=VAR<nn
		VAR=ma.array(VAR,mask=mask) 
		return VAR
	
	def eliminate_isolated_point(self,VAR):
		ntheta=VAR.shape[0]
		nr=VAR.shape[1]
	#if there are less than three points have value in the surrounding (xxx*2+1)^2 points
	#then regard this point as an isolated point
		ii_rember=[]
		jj_rember=[]
		xxx=1
		for ii in range(xxx,ntheta-xxx):
			for jj in range(xxx,nr-xxx):
				if VAR[ii,jj]!=0.0:
					npoints=0
					for kk in range(ii-xxx,ii+xxx+1):
						for ll in range(jj-xxx,jj+xxx+1):
							if VAR[kk,ll]!=0.0:
								npoints=npoints+1
					if npoints<3:
						ii_rember.append(ii)
						jj_rember.append(jj)
		for ii in range(len(ii_rember)):
				VAR[ii_rember[ii],jj_rember[ii]]=0.0
	#if the differnce of the point and the average of the surrounding (xxx*2+1)^2 points
	#is larger than 20 dbz, then eliminate it
	        xxx=2
	        for ii in range(xxx,ntheta-xxx):
	                for jj in range(xxx,nr-xxx):
	                        point_ave=(sum([item for item in VAR[ii-xxx:ii+xxx+1,jj-xxx:jj+xxx+1].reshape((xxx*2+1)**2)])-VAR[ii,jj])/(xxx*2.0+1.)**2
	                        if abs(point_ave-VAR[ii,jj])>20.0:
	                                VAR[ii,jj]=0.0
		return VAR
	
	def adaptive_barnes_interpolation(self,VAR,EA,AA,RR,rscan):
	#this function is adaptive barnes interpolation, the rscan is points
	#for SA/SB doppler radar, one bin is 1 km
	#we use rscan=2 which means the scan radius is 2 km
	#if there are less than 3 records, then we do not apply the interpolation
		ntheta=VAR.shape[0]
		nr=VAR.shape[1]
		k_r=1.0
		k_theta=0.76
		k_phi=0.76
		for ii in range(rscan,ntheta-rscan):
			for jj in range(rscan,nr-rscan):
				if VAR[ii,jj]==0.0:
					npoints=0
					for kk in range(ii-rscan,ii+rscan+1):
						for ll in range(jj-rscan,jj+rscan+1):
							if VAR[kk,ll]!=0.0:
								npoints=npoints+1
					if npoints>=3:
						newVAR=0.0
						newWEIGHT=0.0
						for kk in range(ii-rscan,ii+rscan+1):
							for ll in range(jj-rscan,jj+rscan+1):
								tmp=-(RR[kk,ll]-RR[ii,jj])**2/k_r-(AA[kk,ll]-AA[ii,jj])**2/k_theta-(EA[kk,ll]-EA[ii,jj])**2/k_phi
								weight=np.exp(tmp)
								newVAR=newVAR+weight*VAR[kk,ll]
								newWEIGHT=newWEIGHT+weight
						VAR[ii,jj]=newVAR/newWEIGHT
		return VAR
	
	def n_points_filter_m_times(self,VAR,nn,mm):
	#this function is used to conduct the n points filter in both radial and tangential direction m times
		ntheta=VAR.shape[0]
		nr=VAR.shape[1]
		nn=nn/2
		counts=1
		while counts<=mm:
			for ii in range(nn,ntheta-nn):
				for jj in range(nr):
					VAR[ii,jj]=(sum([item for item in VAR[ii-nn:ii+nn+1,jj].reshape(2*nn+1)]))/(2.0*nn+1)
			for ii in range(ntheta):
				for jj in range(nn,nr-nn):
					VAR[ii,jj]=(sum([item for item in VAR[ii,jj-nn:jj+nn+1].reshape(2*nn+1)]))/(2.0*nn+1)
			counts=counts+1
		return VAR
	
	def draw_radar_on_the_map(self,VAR,nx,ny,lat,lon,file_path,dpi):
		m = Basemap(projection='mill',llcrnrlat=21,urcrnrlat=25,llcrnrlon=111,urcrnrlon=116,lat_ts=25,resolution='h')
		m.bluemarble()
		nyy=lon+ny/110.0
		nxx=lat+nx/110.0
		im=m.pcolormesh(nyy, nxx, VAR,vmin=20,vmax=50,latlon=True)
		m.drawmapboundary()
		m.drawcoastlines()
		m.drawcountries()
		m.drawstates()
		m.drawparallels(np.arange(21.,25,1),labels=[1,0,0,1])
		m.drawmeridians(np.arange(111.,116,1),labels=[0,0,0,1])
		cbar = plt.colorbar()
		plt.savefig(file_path,dpi=dpi)
	
	def fast_draw(self,VAR,nx,ny,file_path,dpi):
		plt.pcolor(ny, nx, VAR, cmap='jet')
		plt.axis([ny.min(), ny.max(), nx.min(), nx.max()])
		plt.colorbar()
		plt.savefig(file_path,dpi=dpi)
	
	def super_obs(self,VAR,cell_range,cell_azimuth,max_range):
		ntheta=VAR.shape[0]
		nr=VAR.shape[1]
		half_cell_azimuth=cell_azimuth/2
		half_cell_range=cell_range/2
		out=np.zeros([ntheta,nr],dtype=np.float)
		for ii in range(half_cell_azimuth,ntheta-half_cell_azimuth,cell_azimuth):
			for jj in range(half_cell_range,nr-half_cell_range,cell_range):
				out[ii-half_cell_azimuth:ii+half_cell_azimuth+1,jj-half_cell_range:jj+half_cell_range+1]=(sum([item for item in VAR[ii-half_cell_azimuth:ii+half_cell_azimuth+1,jj-half_cell_range:jj+half_cell_range+1].reshape(cell_azimuth*cell_range)]))/(1.0*cell_azimuth*cell_range)
		out[:,max_range:]=0.0
		return out
