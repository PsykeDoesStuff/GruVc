every application has some sort of layer running regardless so why shouldnt mine?
each layer needs to be able to communicate with eachother, im gonna use events since its the most flexable
and allows me to reuse the same system in game. 


what is a layer?
- is it a container?
it *does* store specific data about its given type, 
so for the editor it contains stuff relating to the editor,
for the runtime it cdontains all basic information for running it

layers themselves could just be tags?
but that wouldnt really work since i need to store data so making them a struct would
be the better approach
should the layers be independent of the application while loop?
hell noo that wouldnt even make sense


im gonna give the application a layerstack, that way it should be a little easier to orginise everything
the editor itself wont really have any control over the layerstack anyway so working on this part of the backend
isnt really a bad idea


Layers need:
- methods
    -on_attach
    -on_detach
    -update



