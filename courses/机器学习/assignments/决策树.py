import pandas as pd
import numpy as np
from math import log2
from collections import Counter

# --- 数据与基础工具 ---
columns = ['色泽', '根蒂', '敲声', '纹理', '脐部', '触感', '好瓜']
# (数据保持不变)
train_data = [    ['青绿', '蜷缩', '浊响', '清晰', '凹陷', '硬滑', '是'],

    ['乌黑', '蜷缩', '沉闷', '清晰', '凹陷', '硬滑', '是'],

    ['乌黑', '蜷缩', '浊响', '清晰', '凹陷', '硬滑', '是'],

    ['青绿', '蜷缩', '沉闷', '清晰', '凹陷', '硬滑', '是'],

    ['浅白', '蜷缩', '浊响', '清晰', '凹陷', '硬滑', '是'],

    ['青绿', '稍蜷', '浊响', '清晰', '稍凹', '软粘', '是'],

    ['乌黑', '稍蜷', '浊响', '稍糊', '稍凹', '软粘', '是'],

    ['乌黑', '稍蜷', '浊响', '清晰', '稍凹', '硬滑', '是'],

    ['乌黑', '稍蜷', '沉闷', '稍糊', '稍凹', '硬滑', '否'],

    ['青绿', '硬挺', '清脆', '清晰', '平坦', '软粘', '否'],

    ['浅白', '硬挺', '清脆', '模糊', '平坦', '硬滑', '否'],

    ['浅白', '蜷缩', '浊响', '模糊', '平坦', '软粘', '否'],

    ['青绿', '稍蜷', '浊响', '稍糊', '凹陷', '硬滑', '否'],

    ['浅白', '稍蜷', '沉闷', '稍糊', '凹陷', '硬滑', '否'],

    ['乌黑', '稍蜷', '浊响', '清晰', '稍凹', '软粘', '否'],

    ['浅白', '蜷缩', '浊响', '模糊', '平坦', '硬滑', '否'],

    ['青绿', '蜷缩', '沉闷', '稍糊', '稍凹', '硬滑', '否']] 
df_train = pd.DataFrame(train_data, columns=columns)

def get_entropy(data, target='好瓜'):
    """计算信息熵"""
    probs = data[target].value_counts(normalize=True)
    return -sum(p * log2(p) for p in probs)

def get_gini(data, target='好瓜'):
    """计算基尼值"""
    probs = data[target].value_counts(normalize=True)
    return 1 - sum(p**2 for p in probs)

# --- 划分准则计算 ---
def calculate_split_score(data, attr, method):
    n = len(data)
    unique_vals = data[attr].unique()
    
    if method == 'gini':
        # 计算基尼指数
        return sum((len(data[data[attr] == v]) / n) * get_gini(data[data[attr] == v]) 
                   for v in unique_vals)
    
    ent_D = get_entropy(data)
    ent_after = sum((len(data[data[attr] == v]) / n) * get_entropy(data[data[attr] == v]) 
                    for v in unique_vals)
    ig = ent_D - ent_after
    
    if method == 'info_gain':
        return ig
    
    # 增益率需计算IV
    iv = -sum((len(data[data[attr] == v]) / n) * log2(len(data[data[attr] == v]) / n) 
              for v in unique_vals)
    return ig / iv if iv != 0 else 0

# --- 树模型结构 ---
class DecisionTreeNode:
    def __init__(self, label=None, split_attr=None):
        self.label = label
        self.split_attr = split_attr
        self.children = {}

def build_tree(data, attrs, method):
    target = '好瓜'
    labels = data[target].unique()
    
    # 基准情况：纯度已达标或无属性可选
    if len(labels) == 1:
        return DecisionTreeNode(label=labels[0])
    if not attrs or all(data[attrs].nunique() == 1):
        return DecisionTreeNode(label=data[target].mode()[0])

    # 选择最优属性
    best_attr = None
    if method == 'gini':
        best_attr = min(attrs, key=lambda a: calculate_split_score(data, a, 'gini'))
    else:
        best_attr = max(attrs, key=lambda a: calculate_split_score(data, a, method))

    node = DecisionTreeNode(split_attr=best_attr)
    remaining_attrs = [a for a in attrs if a != best_attr]
    
    for val, group in data.groupby(best_attr):
        node.children[val] = build_tree(group, remaining_attrs, method)
    return node

def predict(node, sample):
    if node.label is not None:
        return node.label
    return predict(node.children.get(sample[node.split_attr], next(iter(node.children.values()))), sample)

# --- 执行 ---
test_sample = {'色泽':'青绿', '根蒂':'蜷缩', '敲声':'浊响', '纹理':'清晰', '脐部':'凹陷', '触感':'硬滑'}
attrs = ['色泽','根蒂','敲声','纹理','脐部','触感']

for m in ['info_gain', 'gain_ratio', 'gini']:
    tree = build_tree(df_train, attrs, m)
    print(f"{m} 预测结果：{predict(tree, test_sample)}")