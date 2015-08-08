#include "Scene.h"

#include "Whisperer.h"

Scene::Scene()
    : mBackgroundSurface(Whisperer::WINDOW_WIDTH, Whisperer::WINDOW_HEIGHT)
{
}

void Scene::BlitBackgroundSurface(Surface* background, int x, int y)
{
    mBackgroundSurface.blitSurface(background, x, y);
}

void Scene::CopyBackgroundSurface(Surface* background, int x, int y)
{
    mBackgroundSurface.copySurface(background, x, y);
}

void Scene::AddBackgroundImage(string key, int x, int y)
{
    mBackgroundImages[key] = Point(x, y);
}

void Scene::AddForegroundImage(string key, int x, int y)
{
    mForegroundImages[key] = Point(x, y);
}

void Scene::ClearImages()
{
    mBackgroundImages.clear();
    mForegroundImages.clear();
}

void Scene::Update(int deltaMS)
{
    // TODO update surface tweens
    // TODO update dialog boxes
}

void Scene::Show(Graphics& graphics)
{
    for (auto it = mBackgroundImages.begin(); it != mBackgroundImages.end(); ++it)
    {
        graphics.addBackgroundImage(it->first, it->first,
                it->second.x, it->second.y);
    }

    for (auto it = mForegroundImages.begin(); it != mForegroundImages.end(); ++it)
    {
        graphics.addForegroundImage(it->first, it->first,
                it->second.x, it->second.y);
    }
}

void Scene::Draw(Graphics& graphics)
{
    graphics.clear();

    graphics.blitSurface(&mBackgroundSurface, 0, 0);

    // TODO draw surface tweens
    // TODO draw dialog boxes
}

void Scene::Hide(Graphics& graphics)
{
    graphics.clear();

    for (auto it = mBackgroundImages.begin(); it != mBackgroundImages.end(); ++it)
    {
        graphics.removeBackgroundImage(it->first);
    }

    for (auto it = mForegroundImages.begin(); it != mForegroundImages.end(); ++it)
    {
        graphics.removeForegroundImage(it->first);
    }
}

bool Scene::DrawEveryFrame()
{
    return false; // TODO if there are tweens/dialogs return true
}
