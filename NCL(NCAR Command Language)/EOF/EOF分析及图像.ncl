;========================================================
;用于计算并画出Geopotential Height的EOF分析及图像
;========================================================


load "$NCARG_ROOT/lib/ncarg/nclscripts/csm/gsn_code.ncl"
load "$NCARG_ROOT/lib/ncarg/nclscripts/csm/gsn_csm.ncl"
load "$NCARG_ROOT/lib/ncarg/nclscripts/csm/contributed.ncl"

begin

filepath="G:/hgt.mon.mean.nc"
data=addfile(filepath,"r")

;===============设置做分解的地区与时间段=================
lonL=72.                              
lonR=136.
latS=17.
latN=55.
yrStrt=1990                           
yrLast=2003

TIME=data->time

iy=ut_calendar(TIME,-1)/100           ;将资料时间转为世界时

t=ind(iy.ge.yrStrt .and. iy.le.yrLast);选取所需时段的序号

neof   = 3                            ; number of EOFs


;====================关于EOF函数的一些属性设置===========
optEOF = True       
optEOF@jopt = 0  
optETS = False
optAve=0

;=============读取资料并将格式转换成与EOF函数相适应======
hgt=data->hgt(t,0,:,:)
hgt=lonFlip(hgt)
HGT=hgt({lat|latS:latN},{lon|lonL:lonR},time|:)


;=============进行EOF及相关时间系数的处理================
eof=eofunc_Wrap(HGT,neof,optEOF)
eof_ts=eofunc_ts_Wrap (HGT,eof,optETS)
year = ut_calendar(eof_ts&time,4)
ave=runave_n_Wrap(eof_ts,7,optAve,1)     ;对时间系数作滑动平均(7 mons)  
year_ave=ut_calendar(ave&time,4)


wks=gsn_open_wks("x11","EOF")
gsn_define_colormap(wks,"BlWhRe")


;=============EOF图像的属性设置==========================

res=True

res@gsnDraw=False
res@gsnFrame=False
res@gsnSpreadColors=True
res@gsnAddCyclic=False

res@mpMinLatF=latS
res@mpMaxLatF=latN
res@mpMinLonF=lonL
res@mpMaxLonF=lonR

res@mpDataSetName = "Earth..4"
res@mpDataBaseVersion = "MediumRes"

res@mpOutlineOn = True
res@mpOutlineSpecifiers = (/"China:states","Taiwan"/)
res@mpMaskAreaSpecifiers = (/"China:states","Taiwan"/)
res@mpPerimOn   = True
res@mpGridMaskMode  = "MaskLand"
res@mpOceanFillColor = 0
res@mpInlandWaterFillColor = 0

res@cnFillOn=True
res@cnLinesOn=False
res@cnFillDrawOrder="PreDraw"

res@lbLabelBarOn         = False


;==========EOF时间系数图像的属性设置=====================

rts           = True

rts@gsnScale  = True 
rts@gsnDraw   = False
rts@gsnFrame  = False
             
rts@gsnYRefLine           = 0.         ;设置参考线   
rts@gsnXYBarChart         = True       ;选择画的图为柱状图  
rts@gsnAboveYRefLineColor = "white"    ;参考线上下部图像与参考线     
rts@gsnBelowYRefLineColor = "white"    ;围成图形的颜色设置

rts@vpWidthF  = 0.70
rts@vpHeightF = 0.26
rts@tiYAxisString = ""        


;=========滑动平均后的时间系数图像的属性设置=============

r_ave=True
r_ave@gsnScale  = True 
r_ave@gsnDraw   = False
r_ave@gsnFrame  = False
r_ave@xyLineThicknessF = 1.5              ;设置滑动曲线的粗细 
r_ave@xyMarkLineMode  = "MarkLines"       ;设置滑动曲线的形式
r_ave@xyMarker  = 1                       ;设置描绘的数据点的格式
r_ave@xyMarkerSizeF  = 0.03               ;设置数据点的大小


;===============控制板的属性设置=========================

resP                     = True
resP@gsnPanelLabelBar    = True
resP@lbOrientation       = "Vertical"
resP@gsnPanelPerimOn = True
resP@lbLabelAutoStride   = True

  

plot=new((/2,neof/),graphic)

do i=0,neof-1
  res@gsnLeftString  = "EOF"+(i+1)+" of Geopotential Height in China"
  res@gsnRightString = sprintf("%5.1f", eof@pcvar(i)) +"%"
  plot(0,i)=gsn_csm_contour_map(wks,eof(i,:,:),res)
  plot(1,i)=gsn_csm_xy(wks,year,eof_ts(i,:),rts)
  pl=gsn_csm_xy(wks,year_ave,ave(i,:),r_ave)
  overlay(plot(1,i),pl)
  gsn_panel(wks,plot(:,i),(/2,1/),resP)
end do

end




           

