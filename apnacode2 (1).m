url = 'http://192.168.9.103:8080/shot.jpg';
img  = imread(url);
fh = image(img);
detector = vision.CascadeObjectDetector();
arduino=serial('COM19','BaudRate',9600);
fopen(arduino);
img  = imread(url);
set(fh,'CData',img);
bbox = step(detector, img); % Creating bounding box using detecto
prev=240
emp=zeros(0,4)
if(isempty(bbox)~=1)
     prev=bbox(1);
     prev
end
while(1)
    img  = imread(url);
    set(fh,'CData',img);
    bbox = step(detector, img); % Creating bounding box using detector
    if(isempty(bbox)~=1)
        prev=bbox(1);
        prev
    end
    fprintf(arduino,'%s',char(prev));		
%bbox will show the whole matrix , we just need bbox(1) ie first value to locate face either on right or left, if there is no face we will get value 0
    if ~ isempty(bbox)
        for i=1:size(bbox,1)
            rectangle('position', bbox(i, :), 'lineWidth', 2, 'edgeColor', 'y');
        end
    end
end
%we are not watching images here in matlab because when i tried watching
%images too, i got some errors, instead i deleted it. we can see live video
%for faces in browser itself, this code is just for moving the wheels
%accordingly.