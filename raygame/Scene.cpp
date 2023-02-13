#include "Scene.h"
#include "Transform2D.h"

Scene::Scene()
{
    m_itemCount = 0;
    m_items = DynamicArray<Actor*>();
    m_world = new MathLibrary::Matrix3();
}

MathLibrary::Matrix3* Scene::getWorld()
{
    return m_world;
}

void Scene::addUIElement(Actor* actor)
{
    m_UIElements.add(actor);

    //Adds all children of the UI to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        m_UIElements.add(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeUIElement(int index)
{
    return m_UIElements.remove(index);
}

bool Scene::removeUIElement(Actor* actor)
{
    return m_UIElements.remove(actor);
}

void Scene::addActor(Actor* actor)
{
    m_items.add(actor);

    //Adds all children of the actor to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        m_items.add(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeActor(int index)
{
    return m_items.remove(index);
}

bool Scene::removeActor(Actor* actor)
{
    return m_items.remove(actor);
}

void Scene::start()
{
    m_started = true;
}

void Scene::update(float deltaTime)
{
    //Updates all actors
    for (int i = 0; i < m_items.getLength(); i++)
    {
        if (!m_items[i]->getStarted())
            m_items[i]->start();

        m_items[i]->update(deltaTime);
    }

    //Checks collision for all actors
    for (int i = 0; i < m_items.getLength(); i++)
    {
        for (int j = 0; j < m_items.getLength(); j++)
        {
            if (m_items[i]->checkForCollision(m_items[j]) && j != i && m_items[j]->getStarted())
                m_items[i]->onCollision(m_items[j]);
        }
    }
}

void Scene::updateUI(float deltaTime)
{
    //Calls update for all actors in UI array
    for (int i = 0; i < m_UIElements.getLength(); i++)
    {
        if (!m_UIElements[i]->getStarted())
            m_UIElements[i]->start();

        m_UIElements[i]->update(deltaTime);
    }
}

void Scene::draw()
{
    //Calls draw for all actors in the array
    for (int i = 0; i < m_items.getLength(); i++)
    {
        m_items[i]->draw();
    }
}

void Scene::drawUI()
{
    //Calls draw for all actors in UI array
    for (int i = 0; i < m_UIElements.getLength(); i++)
    {
        m_UIElements[i]->draw();
    }
}

void Scene::end()
{
    //Calls end for all actors in the array
    for (int i = 0; i < m_items.getLength(); i++)
    {
        if (m_items[i]->getStarted())
            m_items[i]->end();
    }

    m_started = false;
}