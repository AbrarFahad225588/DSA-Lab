import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

mileage=[10000,30000,50000,70000,90000,110000,130000,150000,170000,190000]
price=[28000,24000,20000,16000,12000,8000,6000,4000,2000,1000]

data=pd.DataFrame({'Mileage':mileage,'Price':price})
# sns.scatterplot(data=data, x='Mileage', y='Price')
# plt.title('Car Mileage vs Price')
# plt.show()  
# sns.fitlinplot(data=data, x='Mileage', y='Price', ci=None)
# plt.title('Car Mileage vs Price with Trend Line')
# plt.show()
sns.regplot(data=data, x='Mileage', y='Price', ci=None, scatter_kws={"s": 50, "color": "blue"}, line_kws={"color": "red"})
plt.title('Car Mileage vs Price with Regression Line')  
plt.show()