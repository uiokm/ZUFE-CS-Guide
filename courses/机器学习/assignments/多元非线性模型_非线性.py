from numpy.linalg import inv
from numpy import dot,transpose

x1=[[1,6,36],[1,8,64],[1,10,100],[1,14,14*14],[1,18,18*18]]
y1=[[7],[9],[13],[17.5],[18]]
x=[[1,11,11*11],[1,18,18*18]]
print("回归参数：\n",dot(inv(dot(transpose(x1),x1)),dot(transpose(x1),y1)))
print("预测结果：\n",dot(x,dot(inv(dot(transpose(x1),x1)),dot(transpose(x1),y1))))