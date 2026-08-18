import pandas as pd
from sklearn.naive_bayes import CategoricalNB
from sklearn.preprocessing import OrdinalEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline


data = {
    "色泽": ["青绿","乌黑","乌黑","青绿","浅白","青绿","乌黑","乌黑","乌黑","青绿","浅白","浅白","青绿","浅白","乌黑","浅白","青绿"],
    "根蒂": ["蜷缩","蜷缩","蜷缩","蜷缩","蜷缩","稍蜷","稍蜷","稍蜷","稍蜷","硬挺","硬挺","蜷缩","稍蜷","稍蜷","稍蜷","蜷缩","蜷缩"],
    "敲声": ["浊响","沉闷","浊响","沉闷","浊响","浊响","浊响","浊响","沉闷","清脆","清脆","浊响","浊响","沉闷","浊响","浊响","沉闷"],
    "纹理": ["清晰","清晰","清晰","清晰","清晰","清晰","稍糊","清晰","稍糊","清晰","模糊","模糊","稍糊","稍糊","清晰","模糊","稍糊"],
    "脐部": ["凹陷","凹陷","凹陷","凹陷","凹陷","稍凹","稍凹","稍凹","稍凹","平坦","平坦","平坦","凹陷","凹陷","稍凹","平坦","稍凹"],
    "触感": ["硬滑","硬滑","硬滑","硬滑","硬滑","软粘","软粘","硬滑","硬滑","软粘","硬滑","软粘","硬滑","硬滑","软粘","硬滑","硬滑"],
    "好瓜": ["是","是","是","是","是","是","是","是","否","否","否","否","否","否","否","否","否"]
}
df = pd.DataFrame(data)


X = df.drop(columns="好瓜")
y = df["好瓜"]



model_pipeline = Pipeline([
    ("preprocessor", ColumnTransformer(
        [("ord", OrdinalEncoder(), X.columns)], 
        remainder="passthrough"
    )),
    ("classifier", CategoricalNB(alpha=1.0))
])


model_pipeline.fit(X, y)


test_sample = pd.DataFrame([{
    "色泽": "青绿", "根蒂": "蜷缩", "敲声": "浊响",
    "纹理": "清晰", "脐部": "凹陷", "触感": "硬滑"
}])


prediction = model_pipeline.predict(test_sample)[0]

probs = model_pipeline.predict_proba(test_sample)[0]
classes = model_pipeline.classes_


print(f"预测结果: {prediction}")
for cls, prob in zip(classes, probs):
    print(f"概率 ({cls}): {prob:.4f}")