# display found solution

xlist = [cities_coord.iloc[i,0] for i in result.variables]
ylist = [cities_coord.iloc[i,1] for i in result.variables]

xlist.append(xlist[0])
ylist.append(ylist[0])

plt.figure(figsize=(16,8))
for idx,city in enumerate(cities_coord.values):
    plt.scatter(city[0],city[1])
    plt.text(city[0]-20, city[1]+40, str(idx), fontsize=10)

plt.plot(xlist, ylist, linestyle='-')
plt.plot(xlist, ylist, linestyle='-')
plt.axis('scaled')
plt.show()
