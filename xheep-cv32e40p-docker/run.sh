CONTAINER_NAME=xheep-normaltoolchain

if [ "$(docker ps -a -q -f name=^${CONTAINER_NAME}$)" ]; then
  echo "Container '$CONTAINER_NAME' exists. Removing..."
  docker rm $CONTAINER_NAME

  if [ $? -ne 0 ]; then
    echo "Failed to remove the container '$CONTAINER_NAME'."
  fi
fi

docker run -it --name $CONTAINER_NAME $CONTAINER_NAME:latest /bin/bash -c "echo 'Container Started'; /bin/bash"
