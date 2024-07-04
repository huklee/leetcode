import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores["rank"] = scores["score"].rank(method = "dense", ascending=False)
    scores = scores.sort_values(by="score", ascending=False)
    scores = scores.drop(columns=["id"])

    return scores
