# Shell

ETKF脚本：运行WRFDA中ETKF的脚本

gen_be_run：利用NMC方法生成背景误差协方差矩阵需要一段时间模式的结果，脚本用于自动运行模式，模式运行起止时间根据met_em*文件获取

PBS作业卡：PBS作业卡范例

WRF模式运行：用shell脚本实现WRF自动运行，学习shell脚本时的第一个例子，仅备份

不断重新初始化运行WRF：不断重新初始化的方式运行WRF，模式运行起止时间根据met_em*文件获取

批量real：批量运行real.exe

批量运行COSP与后处理：云模拟器COSP运行与后处理绘图

运行WRFDA-4DVAR：运行WRFDA中4DVAR的脚本，每个过程分开便于调试

add_user：批量新增用户

l2tp.sh: 自动配置l2tp的VPN