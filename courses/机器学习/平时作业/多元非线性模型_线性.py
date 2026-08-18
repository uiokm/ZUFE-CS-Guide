from numpy.linalg import inv
from numpy import dot,transpose

x1=[[1,6,2],[1,8,1],[1,10,0],[1,14,2],[1,18,0]]
y1=[[7],[9],[13],[17.5],[18]]
x=[[1,8,2],[1,9,0],[1,11,2],[1,16,2],[1,12,0]]
print("回归参数：\n",dot(inv(dot(transpose(x1),x1)),dot(transpose(x1),y1)))
print("预测结果：\n",dot(x,dot(inv(dot(transpose(x1),x1)),dot(transpose(x1),y1))))