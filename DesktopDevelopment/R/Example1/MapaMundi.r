install.packages("foreign")
install.packages ("ggplot2")
install.packages ("ggmap")
install.packages ("reshape2")
install.packages ("maps")
install.packages ("Cairo")

library(foreign)
library(ggplot2)
library(ggmap)
library(reshape2)
library(maps)
library(Cairo)

attach(economia)

econ <- subset(economia, select=c(country, overall_score))

world = map_data("world") 

world1 <- merge (world, econ, by.x="region", by.y="country", all.x=T, all.y=F) 
world1 <- world1[order(world1$order),] 

m0 <- ggplot(data=world1)
m1 <- m0 + geom_polygon(aes(x=long, y=lat, group=group, fill= overall_score))
+ coord_equal()
m2 <- m1 + geom_path(aes(x=long, y=lat, group=group), color='grey', size=.1)
m3 <- m2 + scale_fill_gradient(low = "lightgreen", high = "darkgreen")
m3

