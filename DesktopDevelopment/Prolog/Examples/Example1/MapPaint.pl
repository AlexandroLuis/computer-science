country(antilles). 
country(argentina).
country(bolivia). 
country(brazil).
country(columbia). 
country(chile).
country(ecuador). 
country(french_guiana).
country(guyana). 
country(paraguay).
country(peru). 
country(surinam).
country(uruguay). 
country(venezuela).
beside(antilles,venezuela). 
beside(argentina,bolivia).
beside(argentina,brazil). 
beside(argentina,chile).
beside(argentina,paraguay). 
beside(argentina,uruguay).
beside(bolivia,brazil). 
beside(bolivia,chile).
beside(bolivia,paraguay). 
beside(bolivia,peru).
beside(brazil,columbia). 
beside(brazil,french_guiana).
beside(brazil,guyana). 
beside(brazil,paraguay).
beside(brazil,peru). 
beside(brazil,surinam).
beside(brazil,uruguay). 
beside(brazil,venezuela).
beside(chile,peru). 
beside(columbia,ecuador).
beside(columbia,peru). 
beside(columbia,venezuela).
beside(ecuador,peru). 
beside(french_guiana,surinam).
beside(guyana,surinam). 
beside(guyana,venezuela).

color( red ).
color( green ).
color( blue ).
color( purple ).

conflict( color( Node1, Color ), color( Node2, Color )) :-
       beside( Node1, Node2 ).
noconflict( _, [] ).
noconflict( Coloring1, [Coloring2 | Colorings] ) :-
    not( conflict( Coloring1, Coloring2 )),
        noconflict( Coloring1, Colorings ).
findcoloring( [], [] ).
findcoloring( [Node | Nodes], [Coloring | Colorings] ) :-
    findcoloring( Nodes, Colorings ),
    Coloring = color( Node, Color ),
    color( Color ),
    noconflict( Coloring, Colorings ).
